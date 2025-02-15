/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:15:15 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/02/15 14:15:17 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_vector	vec_add(t_vector a, t_vector b)
{
	return ((t_vector){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vector	vec_sub(t_vector a, t_vector b)
{
	return ((t_vector){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vector	vec_scale(t_vector v, double scalar)
{
	return ((t_vector){v.x * scalar, v.y * scalar, v.z * scalar});
}

t_vector	vec_negate(t_vector v)
{
	return ((t_vector){-v.x, -v.y, -v.z});
}
