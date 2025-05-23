/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radians_math.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 18:45:23 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/04/28 12:23:43 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define RADIANS_CONST 0.017453292519943295
#define DEGREES_CONST 57.29577951308232

double	degrees_to_radians(double angle)
{
	return (angle * RADIANS_CONST);
}

double	radians_to_degrees(double radians)
{
	return (radians * DEGREES_CONST);
}
