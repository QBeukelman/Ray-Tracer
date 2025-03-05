/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   viewport.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 23:28:14 by hein          #+#    #+#                 */
/*   Updated: 2025/03/04 22:17:05 by hesmolde      ########   odam.nl         */
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
	camera->right = vec_cross(camera->global_up, camera->orientation);
	camera->right = vec_normalize(camera->right);
	// if (camera->right.x < 0)
	// 	camera->right = vec_scale(camera->right, -1);
	camera->right = vec_abs(camera->right);
	printf("camera->right x[%f] y[%f] z[%f]\n", camera->right.x, camera->right.y, camera->right.z);
	camera->up = vec_cross(camera->orientation, camera->right);
	// if (camera->up.y < 0)
	// 	camera->up = vec_scale(camera->up, -1);
	camera->up = vec_abs(camera->up);
	printf("camera->up x[%f] y[%f] z[%f]\n", camera->up.x, camera->up.y, camera->up.z);
	calculate_viewport(camera);
}

