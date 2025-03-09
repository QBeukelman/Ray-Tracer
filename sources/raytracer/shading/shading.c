/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shading.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hein <hein@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/08 23:52:11 by hein          #+#    #+#                 */
/*   Updated: 2025/03/09 01:03:37 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

int	calculate_shading(t_collision *object, t_light *light)
{
	t_vector	light_direction;
	t_colour	colour;
	double		angle_diffusion;

	light_direction = vec_normalize(vec_sub(light->position, object->collision_point));
	angle_diffusion = fmax(0.0, vec_dot(object->surface_normal, light_direction));
	colour.r = object->closest_obj->colour.r * light->brightness * angle_diffusion;
	colour.g = object->closest_obj->colour.g * light->brightness * angle_diffusion;
	colour.b = object->closest_obj->colour.b * light->brightness * angle_diffusion;
	return (colour_to_int(&colour, 255));
}