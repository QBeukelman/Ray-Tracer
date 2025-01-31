/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_loop.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hein <hein@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 15:15:23 by hein          #+#    #+#                 */
/*   Updated: 2025/01/30 16:56:11 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	background_colour(double ray_y)
{
	const t_rgb	white = {1.0, 1.0, 1.0};
	const t_rgb	blue = {0.5, 0.7, 1.0};
	t_rgb		result;
	t_rgb		colour;
	double		blend;

	blend = 0.5 * (ray_y + 1.0);
	result.r = (1.0 - blend) * white.r + blend * blue.r;
	result.g = (1.0 - blend) * white.g + blend * blue.g;
	result.b = (1.0 - blend) * white.b + blend * blue.b;
	colour.r = (int)(255.999 * result.r);
	colour.g = (int)(255.999 * result.g);
	colour.b = (int)(255.999 * result.b);
	return (get_rgba(colour.r, colour.g, colour.b, 255));
}

void	render_image(t_data *d, t_camera_data *c)
{
	t_pixel	pixel;
	t_ray	current_ray;
	int		colour;

	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIDTH)
		{
			current_ray = calculate_ray_direction(c, pixel.x, pixel.y);
			colour = background_colour(current_ray.direction.y);
			mlx_put_pixel(d->img, pixel.x, pixel.y, colour);
			pixel.x++;
		}
		pixel.y++;
	}
}