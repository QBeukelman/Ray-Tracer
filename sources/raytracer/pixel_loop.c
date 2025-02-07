/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_loop.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 15:15:23 by hein          #+#    #+#                 */
/*   Updated: 2025/02/07 15:29:28 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	render_image(t_mlx_data *d, t_camera_data *c)
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
			// Colusion(c_ray) -> Color value of closest obj?

			colour = background_colour(c, current_ray.direction.y);
			mlx_put_pixel(d->img, pixel.x, pixel.y, colour);
			pixel.x++;
		}
		pixel.y++;
	}
}