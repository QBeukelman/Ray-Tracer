/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colour_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/23 11:10:09 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/02/23 11:13:42 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	rgba_to_int(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	colour_to_int(t_colour *colour, int a)
{
	return (colour->r << 24 | colour->g << 16 | colour->b << 8 | a);
}
