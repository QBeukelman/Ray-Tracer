/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   viewport.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hein <hein@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 23:28:14 by hein          #+#    #+#                 */
/*   Updated: 2025/02/28 15:55:10 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define RADIAN_CONST 0.0174533

static void	calculate_viewport(t_camera *c)
{
	t_vector	height_scaled;
	t_vector	width_scaled;
	t_vector	scaled_origin;

	c->viewport.distance = 1.0;
	c->fov_radians = c->fov * RADIAN_CONST;

	// printf("fov [%d]  radiance [%f]\n", c->fov, c->fov_radians);

	c->viewport.height = 2 * c->viewport.distance * tan(c->fov_radians / 2);
	c->viewport.width = c->viewport.height * c->aspect_ratio;

	// printf("viewport hight [%f] width [%f]\n", c->viewport.height, c->viewport.width);
	scaled_origin = vec_scale(c->position, c->viewport.distance);
	c->viewport.center = vec_add(scaled_origin, c->orientation);
	c->viewport.x_off = c->viewport.width / WIDTH;
	c->viewport.y_off = c->viewport.height / HEIGHT;
	// printf("viewport offsets x[%f], y[%f]\n",c->viewport.x_off, c->viewport.y_off);

	height_scaled = vec_scale(c->up, c->viewport.height / 2);
	width_scaled = vec_scale(c->right, c->viewport.width / 2);
	c->viewport.bottomleft = vec_sub(c->viewport.center, height_scaled);
	c->viewport.bottomleft = vec_sub(c->viewport.bottomleft, width_scaled);

	printf("bottomleft x[%f]y[%f]z[%f]\n", c->viewport.bottomleft.x, c->viewport.bottomleft.y, c->viewport.bottomleft.z);
	// exit(1);
}

void	initialize_viewport(t_camera *camera)
{
	camera->aspect_ratio = (double)WIDTH / (double)HEIGHT;
	camera->global_up.x = 0.0;
	camera->global_up.y = 1.0;
	camera->global_up.z = 0.0;
	camera->right = vec_cross(camera->global_up, camera->orientation);
	camera->right = vec_normalize(camera->right);
	camera->up = vec_cross(camera->orientation, camera->right);
	calculate_viewport(camera);

	// printf("camera data after initializing viewport in render image\n");
	// printf("viewport offsets x[%f], y[%f]\n",camera->viewport.x_off, camera->viewport.y_off);
	// exit (1);
}
