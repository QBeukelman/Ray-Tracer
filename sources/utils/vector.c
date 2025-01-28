/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 17:15:21 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/01/28 21:14:43 by hesmolde      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	vec_add(t_vector a, t_vector b)
{
	return (t_vector){a.x + b.x, a.y + b.y, a.z + b.z};
}

t_vector	vec_sub(t_vector a, t_vector b)
{
	return (t_vector){a.x - b.x, a.y - b.y, a.z - b.z};
}

t_vector	vec_scale(t_vector v, double scalar)
{
	return (t_vector){v.x * scalar, v.y * scalar, v.z * scalar};
}

t_vector	vec_negate(t_vector v) 
{
	return (t_vector){-v.x, -v.y, -v.z};
}

