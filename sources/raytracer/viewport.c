/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   viewport.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 23:28:14 by hein          #+#    #+#                 */
/*   Updated: 2025/03/08 16:00:39 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define RADIAN_CONST 0.0174533

t_vector	vec_abs(t_vector v)
{
	if (v.x < 0)
		v.x = fabs(v.x);
	if (v.y < 0)
		v.y = fabs(v.y);
	if (v.z < 0)
		v.z = fabs(v.z);
	return (v);
}

t_vector	**allocate_rays()
{
	t_vector	**rays;
	int			y;

	// memset(*rays, 0, (WIDTH * HEIGHT * sizeof(t_vector)));
	rays = (t_vector **)malloc(HEIGHT * sizeof(t_vector *));
	if (rays == NULL)
	{
		return (NULL);
	}
	rays[0] = (t_vector *)malloc(WIDTH * HEIGHT * sizeof(t_vector));
	if (rays[0] == NULL)
	{
		free (rays);
		return (NULL);
	}
	y = 1;
	while (y < HEIGHT)
	{
		rays[y] = rays[0] + (y * WIDTH);
		y++;
	}
	return (rays);
}

// void	generate_rays(t_vector **rays, t_camera *c)
// {
// 	const double	aspect_ratio = (double)WIDTH / (double)HEIGHT; 
// 	const double	fov_tan = tan((c->fov * RADIAN_CONST) / 2);
// 	t_pixel			p;
// 	t_vector		origin;
// 	t_vector		worldpixel;
	
// 	p.y = 0;
// 	while (p.y < HEIGHT)
// 	{
// 		p.x = 0;
// 		while (p.x < WIDTH)
// 		{
// 			p.ndc_x = (p.x + 0.5) / WIDTH;
// 			p.ndc_y = (p.y + 0.5) / HEIGHT;
// 			p.camera_x = (((2 * p.ndc_x) - 1) * fov_tan) * aspect_ratio;
// 			p.camera_y = (1 - (2 * p.ndc_y)) * fov_tan;
// 			origin = vec_set(0,0,0);
// 			worldpixel = vec_set(p.camera_x, p.camera_y, -1);
// 			rays[p.y][p.x] = vec_normalize(vec_sub(worldpixel, origin));
// 			p.x++;
// 		}
// 		p.y++;
// 	}
// 	printf("fov_tan = %f for FOV %d\n", fov_tan, c->fov);
// }

void	generate_rays(t_vector **rays, t_camera *c)
{
	const double	aspect_ratio = (double)WIDTH / (double)HEIGHT; 
	const double	fov_radians = tan((c->fov * RADIAN_CONST) / 2);
	t_pixel			p;
	t_vector		origin;
	t_vector		worldpixel;
	
	p.y = 0;
	while (p.y < HEIGHT)
	{
		p.x = 0;
		while (p.x < WIDTH)
		{
			p.ndc_x = (p.x + 0.5) / WIDTH;
			p.ndc_y = (p.y + 0.5) / HEIGHT;
			p.camera_x = ((2 * p.ndc_x) - 1);
			p.camera_y = (1 - (2 * p.ndc_y)) * aspect_ratio;
			p.camera_x *= fov_radians;
			p.camera_y *= fov_radians;
			worldpixel = vec_set(p.camera_x, p.camera_y, 1);
			rays[p.y][p.x] = vec_normalize(worldpixel);
			p.x++;
		}
		p.y++;
	}
	printf("fov_tan = %f for FOV %d\n", fov_radians, c->fov);
}

static void	calculate_viewport(t_camera *c)
{
	t_vector	height_scaled;
	t_vector	width_scaled;
	t_vector	scaled_orientation;
	t_vector	pixel_centered;

	c->viewport.distance = 1.0;
	c->fov_radians = c->fov * RADIAN_CONST;
	c->viewport.height = 2 * c->viewport.distance * tan(c->fov_radians / 2);
	c->viewport.width = c->viewport.height * ((double)WIDTH / (double)HEIGHT);
	printf("width [%f] height [%f] makes aspect ratio [%f]\n", c->viewport.width, c->viewport.height, c->viewport.width / c->viewport.height);
	scaled_orientation = vec_scale(c->orientation, c->viewport.distance);
	printf("scaled orientation x[%f] y[%f] z[%f]\n", c->orientation.x, c->orientation.y, c->orientation.z);
	c->viewport.center = vec_add(scaled_orientation, c->position);
	printf("viewport center x[%f] y[%f] z[%f]\n", c->viewport.center.x, c->viewport.center.y, c->viewport.center.z);
	c->viewport.horizontal = vec_set(c->viewport.width, 0, 0);
	c->viewport.vertical = vec_set(0, c->viewport.height, 0);
	c->viewport.x_off = vec_div(c->viewport.horizontal, (WIDTH - 1));
	c->viewport.y_off = vec_div(c->viewport.vertical, (HEIGHT - 1));
	printf("offsets x - x[%f] y[%f] z[%f]\n", c->viewport.x_off.x, c->viewport.x_off.y, c->viewport.x_off.z);
	printf("offsets y - x[%f] y[%f] z[%f]\n", c->viewport.y_off.x, c->viewport.y_off.y, c->viewport.y_off.z);
	width_scaled = vec_scale(c->right, c->viewport.width / 2);
	printf("width_scaled x - x[%f] y[%f] z[%f]\n", width_scaled.x, width_scaled.y, width_scaled.z);
	height_scaled = vec_scale(c->up, c->viewport.height / 2);
	printf("height_scaled x - x[%f] y[%f] z[%f]\n", height_scaled.x, height_scaled.y, height_scaled.z);
	c->viewport.topleft = vec_sub(c->viewport.center, height_scaled);
	c->viewport.topleft = vec_sub(c->viewport.topleft, width_scaled);
	pixel_centered = vec_add(vec_div(c->viewport.x_off, 2), \
			vec_div(c->viewport.y_off, 2));
	printf("centered pixel x[%f] y[%f] z[%f]\n", pixel_centered.x, pixel_centered.y, pixel_centered.z);
	c->viewport.topleft = vec_add(c->viewport.topleft, pixel_centered);

	printf("topleft x[%f] y[%f] z[%f]\n", c->viewport.topleft.x, c->viewport.topleft.y, c->viewport.topleft.z);
}

double cleanZero(double x)
{
    return (x == -0.0) ? 0.0 : x;
}

void	initialize_viewport(t_camera *camera)
{
	camera->aspect_ratio = (double)WIDTH / (double)HEIGHT;
	if (fabs(camera->orientation.y) < 0.99)
	{
		printf("1\n");
		camera->global_up = vec_set(0, 1, 0);
	}
	else
	{
		printf("2\n");
		camera->global_up = vec_set(0, 0, 1);
	}
	camera->right = vec_normalize(vec_cross(camera->orientation, camera->global_up));
	// camera->right = vec_normalize(camera->right);
	// if (camera->right.x < 0)
	// 	camera->right = vec_scale(camera->right, -1);
	// camera->right = vec_abs(camera->right);
	camera->up = vec_cross(camera->right, camera->orientation);
	// if (camera->up.y < 0)
	// 	camera->up = vec_scale(camera->up, -1);
	// camera->up = vec_abs(camera->up);
	printf("camera->forward			x[%f] y[%f] z[%f]\n", camera->orientation.x, camera->orientation.y, camera->orientation.z);
	printf("camera->right			x[%f] y[%f] z[%f]\n", camera->right.x, camera->right.y, camera->right.z);
	printf("camera->up			x[%f] y[%f] z[%f]\n", camera->up.x, camera->up.y, camera->up.z);
	printf("dot product between up and forward [%f]\n", vec_dot(camera->orientation, camera->up));
	printf("dot product between up and right [%f]\n", vec_dot(camera->right, camera->up));
	printf("dot product between right and forward [%f]\n", vec_dot(camera->orientation, camera->right));
	// exit(1);
	// calculate_viewport(camera);
}

