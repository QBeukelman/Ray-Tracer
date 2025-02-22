/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:23 by hein              #+#    #+#             */
/*   Updated: 2025/02/22 14:14:23 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	calculate_ray(t_camera *c, int x, int y)
{
	t_vector	current_x_offset;
	t_vector	current_y_offset;
	t_vector	three_d_pixel;
	t_ray		new_ray;

	new_ray.origin = c->position;
	current_x_offset = vec_scale(c->right, (x * c->viewport.x_off));
	current_y_offset = vec_scale(c->up, ((HEIGHT - y) * c->viewport.y_off));
	three_d_pixel = vec_add(c->viewport.bottomleft, current_x_offset);
	three_d_pixel = vec_add(three_d_pixel, current_y_offset);
	new_ray.raw_direction = vec_sub(three_d_pixel, c->position);
	new_ray.direction = vec_normalize(new_ray.raw_direction);
	return (new_ray);
}

static int ray_color_for_obj(t_object *object, t_ray *ray, double *nearest)
{
	switch (object->type)
	{
		case SPHERE:
			return (hit_sphere(object, &ray, &nearest));
		default:
			return (0);
	}
	return (0);
}

static int ray_color(t_scene *scene, t_ray ray)
{
	t_object	*current_object;
	int			color;
	double		nearest;
	t_object	*closest;

	current_object = scene->objects;
	nearest = INFINITY;
	closest = NULL;
	while (current_object)
	{
		if (ray_color_for_obj(scene, &ray, &nearest))
			closest = &current_object;
		current_object = current_object->next;
	}

	if (closest)
		color = 1;
	else
		color = background(&(scene->camera), ray.direction.y);
		
	return (color);
}

void	render_image(t_mlx_data *mlx, t_scene *scene)
{
	t_pixel	pixel;
	t_ray	current_ray;
	int		colour;

	pixel.y = 0;
	initialize_viewport(&(scene->camera));
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIDTH)
		{
			current_ray = calculate_ray(&(scene->camera), pixel.x, pixel.y);
			colour = ray_color(scene, current_ray);
			
			mlx_put_pixel(mlx->img, pixel.x, pixel.y, colour);
			pixel.x++;
		}
		pixel.y++;
	}
}
