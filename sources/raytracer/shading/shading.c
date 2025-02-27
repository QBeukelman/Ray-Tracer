/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shading.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hein <hein@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/27 11:53:16 by hein          #+#    #+#                 */
/*   Updated: 2025/02/27 12:49:54 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

int	calculate_shading(t_collision *object, t_light *light)
{
	t_vector	light_direction;
	t_colour	colour;
	double		angle_intensity;

	light_direction = vec_normalize(vec_sub(light->position, object->collision_point));
	angle_intensity = fmax(0.0, vec_dot(object->surface_normal, light_direction));

	printf("Intensity[%f]\n", angle_intensity);
	colour.r = object->closest_obj->colour.r * light->brightness * angle_intensity;
	colour.g = object->closest_obj->colour.g * light->brightness * angle_intensity;
	colour.b = object->closest_obj->colour.b * light->brightness * angle_intensity;

	printf("R[%f]\nG[%f]\nB[%f]\n", colour.r, colour.g, colour.b);
	return (colour_to_int(&colour, 255));
}
