/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/04 22:03:41 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/04 22:43:08 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

bool plane_collision(t_object *plane, t_ray ray, t_collision *collision)
{
	const double denominator = vec_dot(plane->orientation, plane->position);
	
	// Ray is parallel to the plane
	if (denominator == 0)
		return (false);

	const double t = vec_dot(vec_sub(plane->position, ray.origin), plane->orientation) / denominator;

	// Intercetion is behind the ray origin
	if (t < 0)
		return (false);

	collision->distance = t;
	collision->collision_point = vec_add(ray.origin, vec_scale(ray.direction, t));
	collision->surface_normal = plane->orientation;
	collision->closest_obj = plane;

	return (true);
}
