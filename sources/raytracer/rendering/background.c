/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   background.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/02 18:00:13 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/03/20 21:02:52 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static double	normalize_ray_y(t_camera *c, double ray_y)
{
	const double	min_ray_y = -tan((c->fov * 0.0174533) / 2);
	const double	max_ray_y = tan((c->fov * 0.0174533) / 2);
	double			normalized_y;

	normalized_y = 2 * ((ray_y - min_ray_y) / (max_ray_y - min_ray_y)) - 1;
	return (normalized_y);
}

int	background(t_camera *c, double ray_y)
{
	const t_rgb	white = {1.0, 1.0, 1.0};
	const t_rgb	blue = {0.5, 0.7, 1.0};
	double		blend;
	double		normalized_y;
	t_rgb		colour;

	normalized_y = normalize_ray_y(c, ray_y);
	blend = 0.5 * (normalized_y + 1.0);
	colour.r = fmin(255, (int)(255.999 * ((1.0 - blend) * white.r + blend * blue.r)));
	colour.g = fmin(255, (int)(255.999 * ((1.0 - blend) * white.g + blend * blue.g)));
	colour.b = fmin(255, (int)(255.999 * ((1.0 - blend) * white.b + blend * blue.b)));	
	return (rgba_to_int(colour.r, colour.g, colour.b, 255));
}
