/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 14:15:06 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/05/04 16:11:36 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_vector	vec_set(double x, double y, double z)
{
	return ((t_vector){x, y, z});
}

double	vec_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	vec_cross(t_vector a, t_vector b)
{
	return ((t_vector)
		{
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		});
}

double	vec_length(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

// Return a zero vector if magnitude is 0
t_vector	vec_normalize(t_vector v)
{
	double	length;

	length = vec_length(v);
	if (length == 0)
	{
		return ((t_vector){0, 0, 0});
	}
	return (vec_scale(v, 1.0 / length));
}

t_vector	vec_reflect(t_vector incomming, t_vector normal)
{
	double		dot;
	t_vector	adjustment;
	
	dot = vec_dot(incomming, normal);
	adjustment = vec_scale(normal, dot * 2);
	return (vec_sub(incomming, adjustment));
}
