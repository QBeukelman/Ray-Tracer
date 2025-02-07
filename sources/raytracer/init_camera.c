/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_camera.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/28 12:28:00 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/02/07 15:21:00 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	set_temp_input_data(t_camera_data *camera)
{
	camera->position.x = -50.0;
	camera->position.y = 0.0;
	camera->position.z = 20.0;
	camera->orientation.x = 0.0;
	camera->orientation.y = 0.0;
	camera->orientation.z = 1.0;
	camera->FOV = 70;
}

void	init_viewport(t_camera_data *c)
{
	t_vector	height_scaled;
	t_vector	width_scaled;

	c->viewport.D = 1.0;
	c->FOV_radians = c->FOV * 0.0174533;
	c->viewport.height = 2 * c->viewport.D * tan(c->FOV_radians / 2);
	c->viewport.width = c->viewport.height * c->aspect_ratio;
	c->viewport.center = vec_add(vec_scale(c->position, c->viewport.D), c->orientation);
	c->viewport.x_off = c->viewport.width / WIDTH;
	c->viewport.y_off = c->viewport.height / HEIGHT;
	height_scaled = vec_scale(c->up, c->viewport.height / 2);
	width_scaled = vec_scale(c->right, c->viewport.width / 2);
	c->viewport.bottomleft = vec_sub(c->viewport.center, height_scaled);
	c->viewport.bottomleft = vec_sub(c->viewport.bottomleft, width_scaled);
}

void	init_camera_data(t_camera_data *camera)
{
	set_temp_input_data(camera);
	camera->aspect_ratio = (double)WIDTH / HEIGHT;
	camera->global_up.x = 0.0;
	camera->global_up.y = 1.0;
	camera->global_up.z = 0.0;
	camera->right = vec_cross(camera->global_up, camera->orientation);
	camera->right = vec_normalize(camera->right);
	camera->up = vec_cross(camera->orientation, camera->right);
	init_viewport(camera);
}

t_ray	calculate_ray_direction(t_camera_data *c, int x, int y)
{
	double		current_x_offset;
	double		current_y_offset;
	t_vector	three_d_pixel;
	t_ray		new_ray;

	new_ray.origin = c->position;
	current_x_offset = x * c->viewport.x_off;
	current_y_offset = (HEIGHT - y) * c->viewport.y_off;
	three_d_pixel = vec_add(c->viewport.bottomleft, vec_scale(c->right, current_x_offset));
	three_d_pixel = vec_add(three_d_pixel, vec_scale(c->up, current_y_offset));
	new_ray.raw_direction = vec_sub(three_d_pixel, c->position);
	new_ray.direction = vec_normalize(new_ray.raw_direction);
	return (new_ray);
}
