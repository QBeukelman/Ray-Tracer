/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shading.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/08 23:52:11 by hein          #+#    #+#                 */
/*   Updated: 2025/03/10 13:55:53 by hein          ########   odam.nl         */
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

bool	object_in_shadow(t_shading light_data, t_object *objects)
{
	t_collision	hit;

	if (is_collision(objects, light_data.direction, &hit) == true)
	{
		if (hit.distance <= light_data.distance)
			return (true);
	}
	return (false);
}

t_shading	set_light_data(t_light *light, t_vector collision_point)
{
	t_shading light_data;

	light_data.vector = vec_sub(light->position, collision_point);
	light_data.distance = vec_length(light_data.vector);
	light_data.direction = vec_normalize(light_data.vector);
}

int	calculate_shading(t_collision *col, t_light *light, t_ambi *ambi, t_object *obj)
{
	const t_rgb		ambient = ambient_light(ambi);
	const t_shading	light_data = set_light_data(light, col->collision_point);
	t_colour		colour;
	double			angle_diffusion;

	if (object_in_shadow(light_data, obj) == true)
	{
		// apply only ambient light
	}
	angle_diffusion = fmax(0.0, vec_dot(col->surface_normal, light_data.direction));
	colour.r = col->closest_obj->colour.r * (ambient.r + (light->brightness * angle_diffusion));
	colour.g = col->closest_obj->colour.g * (ambient.g + (light->brightness * angle_diffusion));
	colour.b = col->closest_obj->colour.b * (ambient.b + (light->brightness * angle_diffusion));
	return (colour_to_int(&colour, 255));
}