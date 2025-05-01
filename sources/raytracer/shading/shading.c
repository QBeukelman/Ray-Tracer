/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shading.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/08 23:52:11 by hein          #+#    #+#                 */
/*   Updated: 2025/05/01 19:05:49 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_rgb	ambient_light(t_ambi *ambi)
{
	t_rgb	ambient;

	ambient.r = ambi->color.r * ambi->ratio / 255.0;
	ambient.g = ambi->color.g * ambi->ratio / 255.0;
	ambient.b = ambi->color.b * ambi->ratio / 255.0;
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
	t_color		color;
	double			angle_diffusion;

	if (object_in_shadow(shadow, obj) == true)
	{
		color.r = col->closest_obj->color.r * ambient.r;
		color.g = col->closest_obj->color.g * ambient.g;
		color.b = col->closest_obj->color.b * ambient.b;
		return (color_to_int(&color, 255));
	}
	angle_diffusion = fmax(0.0, vec_dot(col->surface_normal, shadow.ray.direction));
	color.r = fmin(255, fmax(0, col->closest_obj->color.r * (ambient.r + fmax(0, light->brightness * angle_diffusion - ambient.r))));
	color.g = fmin(255, fmax(0, col->closest_obj->color.g * (ambient.g + fmax(0, light->brightness * angle_diffusion - ambient.g))));
	color.b = fmin(255, fmax(0, col->closest_obj->color.b * (ambient.b + fmax(0, light->brightness * angle_diffusion - ambient.b))));
	return (color_to_int(&color, 255));
}