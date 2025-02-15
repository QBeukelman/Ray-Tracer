/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:15:06 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/02/15 14:15:08 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

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
