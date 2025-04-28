/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shading.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/08 23:52:11 by hein          #+#    #+#                 */
/*   Updated: 2025/04/28 22:44:21 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_rgb	ambient_light(t_ambi *ambi)
{
	t_rgb	ambient;

	ambient.r = ambi->colour.r * ambi->ratio / 255.0;
	ambient.g = ambi->colour.g * ambi->ratio / 255.0;
	ambient.b = ambi->colour.b * ambi->ratio / 255.0;
	return (ambient);
}

bool	object_in_shadow(t_shading shadow, t_object *objects)
{
	t_collision	hit;

	ft_memset(&hit, 0, sizeof(t_collision));
	if (is_collision(objects, shadow.ray, &hit) == true)
	{
		if (hit.distance > 1e-4 && hit.distance < shadow.ray_length)
			return (true);
	}
	return (false);
}

static t_shading	set_light_data(t_light *light, t_vector collision_point)
{
	t_shading	shadow;
	t_vector	origin_offset;

	shadow.ray.raw_direction = vec_sub(light->position, collision_point);
	shadow.ray_length = vec_length(shadow.ray.raw_direction);
	shadow.ray.direction = vec_normalize(shadow.ray.raw_direction);
	origin_offset = vec_scale(shadow.ray.direction, 1e-4);
	shadow.ray.origin = vec_add(collision_point, origin_offset);
	return (shadow);
}

int	calculate_shading(t_collision *col, t_light *light, t_ambi *ambi, t_object *obj)
{
	const t_rgb		ambient = ambient_light(ambi);
	const t_shading	shadow = set_light_data(light, col->collision_point);
	t_colour		colour;
	double			angle_diffusion;

	if (object_in_shadow(shadow, obj) == true)
	{
		colour.r = col->closest_obj->colour.r * ambient.r;
		colour.g = col->closest_obj->colour.g * ambient.g;
		colour.b = col->closest_obj->colour.b * ambient.b;
		return (colour_to_int(&colour, 255));
	}
	angle_diffusion = fmax(0.0, vec_dot(col->surface_normal, shadow.ray.direction));
	colour.r = fmin(255, fmax(0, col->closest_obj->colour.r * (ambient.r + fmax(0, light->brightness * angle_diffusion - ambient.r))));
	colour.g = fmin(255, fmax(0, col->closest_obj->colour.g * (ambient.g + fmax(0, light->brightness * angle_diffusion - ambient.g))));
	colour.b = fmin(255, fmax(0, col->closest_obj->colour.b * (ambient.b + fmax(0, light->brightness * angle_diffusion - ambient.b))));
	return (colour_to_int(&colour, 255));
}