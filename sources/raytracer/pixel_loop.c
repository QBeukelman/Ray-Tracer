/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_loop.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 15:15:23 by hein          #+#    #+#                 */
/*   Updated: 2025/03/05 12:13:14 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	calculate_ray(t_camera *c, int x, int y)
{
	t_vector	x_offset;
	t_vector	y_offset;
	t_vector	current_pixel;
	t_ray		new_ray;

	new_ray.origin = c->position;
	x_offset = vec_scale(c->viewport.x_off, x);
	y_offset = vec_scale(c->viewport.y_off, y);
	current_pixel = vec_add(c->viewport.topleft, vec_add(x_offset, y_offset));
	new_ray.raw_direction = vec_sub(current_pixel, c->position);
	new_ray.direction = vec_normalize(new_ray.raw_direction);
	return (new_ray);
}

static bool collision_for_object(t_object *object, t_ray ray, t_collision *collision)
{
	switch (object->type)
	{
		case SPHERE:
			return (sphere_collision(object, ray, collision));
		case PLANE:
			return (plane_collision(object, ray, collision));
		default:
			return (0);
	}
	return (0);
}

static bool is_collision(t_scene *scene, t_ray ray, t_collision *collision)
{
	t_object		*current_object;
	t_collision		temp_collision;
	bool			found_collision;
	double			min_distance;

	found_collision = false;
	min_distance = __DBL_MAX__;
	current_object = scene->objects;
	while (current_object)
	{
		if (collision_for_object(current_object, ray, &temp_collision) &&
			temp_collision.distance > 0 &&
			temp_collision.distance < min_distance)
		{
			min_distance = temp_collision.distance;
			*collision = temp_collision;
			found_collision = true;
		}
		current_object = current_object->next;
	}
	return (found_collision);
}

void	render_image(t_mlx_data *mlx, t_scene *scene)
{
	t_pixel			pixel;
	t_ray			current_ray;
	int				colour;
	t_collision		collision;

	pixel.y = 0;
	initialize_viewport(&(scene->camera));
	print_viewport(scene);

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
