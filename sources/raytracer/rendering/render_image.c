/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_image.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 15:15:23 by hein          #+#    #+#                 */
/*   Updated: 2025/03/10 13:21:38 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

extern int	background(t_camera *c, double ray_y);


// t_ray	calculate_world_ray(t_camera camera, t_vector *ray)
// {
// 	t_ray		new_ray;

// 	new_ray.origin = camera.position;
// 	new_ray.direction.x = ray->x * camera.right.x + ray->y * camera.up.x + ray->z * camera.orientation.x;
// 	new_ray.direction.y = ray->x * camera.right.y + ray->y * camera.up.y + ray->z * camera.orientation.y;
// 	new_ray.direction.z = ray->x * camera.right.z + ray->y * camera.up.z + ray->z * -camera.orientation.z;
// 	new_ray.direction = vec_normalize(new_ray.direction);
// 	return (new_ray);
// }

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

static bool is_collision(t_object *objects, t_ray ray, t_collision *collision)
{
	t_object		*current_object;
	t_collision		temp_collision;
	bool			found_collision;
	double			min_distance;

	found_collision = false;
	min_distance = __DBL_MAX__;
	current_object = objects;
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
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIDTH)
		{
			// current_ray = calculate_world_ray(scene->camera, &(scene->rays)[pixel.y][pixel.x]);
			current_ray.direction = scene->rays[pixel.y][pixel.x];
			if (is_collision(scene->objects, current_ray, &collision))
				colour = calculate_shading(&collision, &(scene->light), &(scene->ambi));
			else
				colour = background(&(scene->camera), current_ray.direction.y);
			mlx_put_pixel(mlx->img, pixel.x, pixel.y, colour);
			pixel.x++;
		}
		pixel.y++;
	}
}
