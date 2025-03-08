/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_loop.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 15:15:23 by hein          #+#    #+#                 */
/*   Updated: 2025/03/08 15:27:45 by hein          ########   odam.nl         */
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
	// x_offset = vec_scale(c->viewport.x_off, (WIDTH - x));
	x_offset = vec_scale(c->viewport.x_off, x);
	y_offset = vec_scale(c->viewport.y_off, (HEIGHT - y));
	current_pixel = vec_add(c->viewport.topleft, vec_add(x_offset, y_offset));
	new_ray.raw_direction = vec_sub(current_pixel, c->position);
	new_ray.direction = vec_normalize(new_ray.raw_direction);
	return (new_ray);
}

t_ray	calculate_world_ray(t_camera camera, t_vector *ray)
{
	t_ray		new_ray;

	new_ray.origin = camera.position;
	new_ray.direction.x = ray->x * camera.right.x + ray->y * camera.up.x + ray->z * camera.orientation.x;
	new_ray.direction.y = ray->x * camera.right.y + ray->y * camera.up.y + ray->z * camera.orientation.y;
	new_ray.direction.z = ray->x * camera.right.z + ray->y * camera.up.z + ray->z * -camera.orientation.z;
	new_ray.direction = vec_normalize(new_ray.direction);
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

int	calculate_shading(t_collision *object, t_light *light)
{
	t_vector	light_direction;
	t_colour	colour;
	double		angle_intensity;

	light_direction = vec_normalize(vec_sub(light->position, object->collision_point));
	angle_intensity = fmax(0.0, vec_dot(object->surface_normal, light_direction));

	// printf("Intensity[%f]\n", angle_intensity);
	colour.r = object->closest_obj->colour.r * light->brightness * angle_intensity;
	colour.g = object->closest_obj->colour.g * light->brightness * angle_intensity;
	colour.b = object->closest_obj->colour.b * light->brightness * angle_intensity;

	// printf("R[%f]\nG[%f]\nB[%f]\n", colour.r, colour.g, colour.b);
	return (colour_to_int(&colour, 255));
}

void	render_image(t_mlx_data *mlx, t_scene *scene)
{
	t_pixel			pixel;
	t_ray			current_ray;
	int				colour;
	t_collision		collision;

	pixel.y = 0;
	initialize_viewport(&(scene->camera));

	// print_viewport(scene);

	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIDTH)
		{
			current_ray = calculate_world_ray(scene->camera, &(scene->rays)[pixel.y][pixel.x]);
			if (pixel.y == 0 && pixel.x == 0)
				printf("ray for pixel 0,0		x[%f] y[%f] z[%f]\n", current_ray.direction.x, current_ray.direction.y, current_ray.direction.z);
			if (pixel.y == 0 && pixel.x == 799)
				printf("ray for pixel 0,799		x[%f] y[%f] z[%f]\n", current_ray.direction.x, current_ray.direction.y, current_ray.direction.z);
			if (pixel.y == 499 && pixel.x == 0)
				printf("ray for pixel 0,499		x[%f] y[%f] z[%f]\n", current_ray.direction.x, current_ray.direction.y, current_ray.direction.z);
			if (pixel.y == 499 && pixel.x == 799)
				printf("ray for pixel 499,799		x[%f] y[%f] z[%f]\n", current_ray.direction.x, current_ray.direction.y, current_ray.direction.z);
			if (pixel.y == (HEIGHT / 2) && pixel.x == (WIDTH / 2))
				printf("ray for the center		x[%f] y[%f] z[%f]\n", current_ray.direction.x, current_ray.direction.y, current_ray.direction.z);
			if (is_collision(scene, current_ray, &collision))
			{
				// colour = calculate_shading(&collision, &(scene->light));
				colour = colour_to_int(&(collision.closest_obj->colour), 255);
			}
			else
				colour = background(&(scene->camera), current_ray.direction.y);
			
			mlx_put_pixel(mlx->img, pixel.x, pixel.y, colour);
			pixel.x++;
		}
		pixel.y++;
	}
	exit (1);
}
