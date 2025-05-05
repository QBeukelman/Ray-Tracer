/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations_reflect.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 21:10:38 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 21:10:56 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_vector	vec_reflect(t_vector incomming, t_vector normal)
{
	double		dot;
	t_vector	adjustment;

	dot = vec_dot(incomming, normal);
	adjustment = vec_scale(normal, dot * 2);
	return (vec_sub(incomming, adjustment));
}
