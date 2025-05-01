/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/01 19:07:01 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/01 19:07:06 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	rgba_to_int(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	color_to_int(t_color *color, int a)
{
	return (color->r << 24 | color->g << 16 | color->b << 8 | a);
}
