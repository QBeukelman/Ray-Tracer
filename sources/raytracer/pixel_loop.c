/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_loop.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 15:15:23 by hein          #+#    #+#                 */
/*   Updated: 2025/02/07 23:48:02 by hesmolde      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	calculate_ray(t_camera *c, int x, int y)
{
	double		current_x_offset;
	double		current_y_offset;
	t_vector	three_d_pixel;
	t_ray		new_ray;

	new_ray.origin = c->position;
	current_x_offset = x * c->viewport.x_off;
	current_y_offset = (HEIGHT - y) * c->viewport.y_off;
	three_d_pixel = vec_add(c->viewport.bottomleft, vec_scale(c->right, current_x_offset));
	three_d_pixel = vec_add(three_d_pixel, vec_scale(c->up, current_y_offset));
	new_ray.raw_direction = vec_sub(three_d_pixel, c->position);
	new_ray.direction = vec_normalize(new_ray.raw_direction);
	return (new_ray);
}

void	render_image(t_mlx_data *mlx, t_scene *scene)
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
			current_ray = calculate_ray(&(scene->camera), pixel.x, pixel.y);
			// Colusion(c_ray) -> Color value of closest obj?

			colour = background(&(scene->camera), current_ray.direction.y);
			mlx_put_pixel(mlx->img, pixel.x, pixel.y, colour);
			pixel.x++;
		}
		pixel.y++;
	}
}