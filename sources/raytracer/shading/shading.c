/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shading.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/08 23:52:11 by hein          #+#    #+#                 */
/*   Updated: 2025/05/04 20:38:45 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

bool	object_in_shadow(t_shading shadow, t_object *objects)
{
	t_collision	hit;

	ft_memset(&hit, 0, sizeof(t_collision));
	if (is_collision(objects, shadow.ray, &hit) == true)
	{
		if (hit.distance > OFFSET && hit.distance < shadow.ray_length)
			return (true);
	}
	return (false);
}

static t_shading	set_light_data(t_light light, t_vector hit, t_ambi ambi)
{
	t_shading	shadow;
	t_vector	origin_offset;

	shadow.ray.raw_direction = vec_sub(light.position, hit);
	shadow.ray_length = vec_length(shadow.ray.raw_direction);
	shadow.ray.direction = vec_normalize(shadow.ray.raw_direction);
	origin_offset = vec_scale(shadow.ray.direction, OFFSET);
	shadow.ray.origin = vec_add(hit, origin_offset);
	shadow.light_energy = fmax(0.0, light.brightness - ambi.ratio);
	return (shadow);
}

int	calculate_shading(t_collision *col, t_scene *scene, t_ray ray)
{
	t_shading	shadow;
	t_rgb		ambient;
	t_rgb		diffuse;
	double		specular;
	t_color		color;

	shadow = set_light_data(scene->light, col->collision_point, scene->ambi);
	ambient = ambient_light(scene->ambi);
	if (object_in_shadow(shadow, scene->objects) == true)
	{
		color.r = col->closest_obj->color.r * ambient.r;
		color.g = col->closest_obj->color.g * ambient.g;
		color.b = col->closest_obj->color.b * ambient.b;
		return (color_to_int(&color, 255));
	}
	diffuse = diffuse_light(col, scene->light.brightness, shadow, ambient);
	specular = specular_light(col, ray, shadow);
	color.r = fmin(255.0, fmax(0.0, diffuse.r + specular));
	color.g = fmin(255.0, fmax(0.0, diffuse.g + specular));
	color.b = fmin(255.0, fmax(0.0, diffuse.b + specular));
	return (color_to_int(&color, 255));
}
