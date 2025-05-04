/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/09 20:16:16 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/05/04 20:38:36 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_rgb	ambient_light(t_ambi ambi)
{
	t_rgb		ambient;

	ambient.r = ambi.color.r * ambi.ratio / 255.0;
	ambient.g = ambi.color.g * ambi.ratio / 255.0;
	ambient.b = ambi.color.b * ambi.ratio / 255.0;
	return (ambient);
}

t_rgb	diffuse_light(t_collision *col, float bright, t_shading r, t_rgb ambi)
{
	t_rgb		color;
	double		angle;

	angle = fmax(0.0, vec_dot(col->surface_normal, r.ray.direction));
	color.r = fmin(255, fmax(0, col->closest_obj->color.r \
			* (ambi.r + fmax(0, bright * angle - ambi.r))));
	color.g = fmin(255, fmax(0, col->closest_obj->color.g \
			* (ambi.g + fmax(0, bright * angle - ambi.g))));
	color.b = fmin(255, fmax(0, col->closest_obj->color.b \
			* (ambi.b + fmax(0, bright * angle - ambi.b))));
	return (color);
}

double	specular_light(t_collision *col, t_ray ray, t_shading r)
{
	t_rgb		color;
	t_vector	reflection;
	t_vector	view_direction;
	double		angle;
	double		specular;

	reflection = vec_reflect(vec_negate(r.ray.direction), col->surface_normal);
	view_direction = vec_negate(ray.direction);
	angle = fmax(vec_dot(view_direction, reflection), 0.0);
	specular = fmin(255.0, fmax(0.0, pow(angle, SHININESS) \
		* r.light_energy * SPECULAR * 255.0));
	return (specular);
}

