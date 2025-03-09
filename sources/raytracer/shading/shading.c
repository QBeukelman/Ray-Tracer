/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shading.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/08 23:52:11 by hein          #+#    #+#                 */
/*   Updated: 2025/03/09 20:02:42 by hesmolde      ########   odam.nl         */
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

int	calculate_shading(t_collision *object, t_light *light, t_ambi *ambi)
{
	const t_rgb	ambient = ambient_light(ambi);
	t_vector		light_direction;
	t_colour		colour;
	double			angle_diffusion;

	light_direction = vec_normalize(vec_sub(light->position, object->collision_point));
	angle_diffusion = fmax(0.0, vec_dot(object->surface_normal, light_direction));
	colour.r = object->closest_obj->colour.r * (ambient.r + (light->brightness * angle_diffusion));
	colour.g = object->closest_obj->colour.g * (ambient.g + (light->brightness * angle_diffusion));
	colour.b = object->closest_obj->colour.b * (ambient.b + (light->brightness * angle_diffusion));
	return (colour_to_int(&colour, 255));
}