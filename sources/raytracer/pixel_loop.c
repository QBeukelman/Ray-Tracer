/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_loop.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 15:15:23 by hein          #+#    #+#                 */
/*   Updated: 2025/02/23 11:11:22 by quentinbeuk   ########   odam.nl         */
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

static bool collision_for_object(t_object *object, t_ray ray, t_collision *collision)
{
	switch (object->type)
	{
		case SPHERE:
			return (sphere_collision(object, ray, collision));
		default:
			return (0);
	}
	return (0);
}

static bool is_collision(t_scene *scene, t_ray ray, t_collision *collision)
{
	t_object	*current_object;
	t_object	*closest;

	current_object = scene->objects;
	closest = NULL;
	while (current_object)
	{
		if (collision_for_object(current_object, ray, collision))
			closest = current_object;
		current_object = current_object->next;
	}
	return (closest != NULL);
}

void	render_image(t_mlx_data *mlx, t_scene *scene)
{
	t_pixel			pixel;
	t_ray			current_ray;
	int				colour;
	t_collision		collision;

	pixel.y = 0;
	initialize_viewport(&(scene->camera));
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIDTH)
		{
			current_ray = calculate_ray(&(scene->camera), pixel.x, pixel.y);
			if (is_collision(scene, current_ray, &collision))
				colour = colour_to_int(&(collision.closest_obj->colour), 255);
			else
				colour = background(&(scene->camera), current_ray.direction.y);
			
			mlx_put_pixel(mlx->img, pixel.x, pixel.y, colour);
			pixel.x++;
		}
		pixel.y++;
	}
}
