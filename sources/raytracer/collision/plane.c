/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/04 22:03:41 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/01 13:56:30 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

double	hit_flat_plane(double *t, t_ray ray, t_vector p, t_vector orientation)
{
	double		denominator;
	t_vector	origin_to_plane;

	origin_to_plane = vec_sub(p, ray.origin);
	denominator = vec_dot(ray.direction, orientation);
	if (denominator == 0 || (denominator > 0 && denominator < 0.01) || (denominator < 0 && denominator > -0.01))
		return (0.0);
	*t = vec_dot(origin_to_plane, orientation) / denominator;
	return (denominator);
}


bool plane_collision(t_object *plane, t_ray ray, t_collision *collision)
{
	double	denominator;
	double	t;

	denominator = hit_flat_plane(&t, ray, plane->position, plane->orientation);
	if (denominator == 0.0 || t < 0)
		return (false);
	collision->distance = t;
	collision->collision_point = vec_add(ray.origin, vec_scale(ray.direction, t));
	if (denominator < 0)
		collision->surface_normal = plane->orientation;
	else
		collision->surface_normal = vec_negate(plane->orientation);
	collision->closest_obj = plane;
	return (true);
}
