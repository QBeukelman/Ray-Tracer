/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:23 by hein              #+#    #+#             */
/*   Updated: 2025/02/15 16:28:47 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	calculate_ray(t_camera *c, int x, int y)
{
	t_vector	current_x_offset;
	t_vector	current_y_offset;
	t_vector	three_d_pixel;
	t_ray		new_ray;

	new_ray.origin = c->position;
	current_x_offset = vec_scale(c->right, (x * c->viewport.x_off));
	current_y_offset = vec_scale(c->up, ((HEIGHT - y) * c->viewport.y_off));
	three_d_pixel = vec_add(c->viewport.bottomleft, current_x_offset);
	three_d_pixel = vec_add(three_d_pixel, current_y_offset);
	new_ray.raw_direction = vec_sub(three_d_pixel, c->position);
	new_ray.direction = vec_normalize(new_ray.raw_direction);
	return (new_ray);
}

# define CONST2 -2.0
# define CONST4 4
static bool hit_sphere(t_object *sphere, t_ray *ray)
{
	t_vector		oc;
	double			a;
	double			b;
	double			c;
	const double	radius_sq = (sphere->diameter/2) * (sphere->diameter/2);
	
	oc = vec_sub(sphere->position, ray->origin);
	a = vec_dot(ray->direction, ray->direction);
	b = CONST2 * vec_dot(ray->direction, oc);
	c = vec_dot(oc, oc) - radius_sq;
	return (((b*b) - CONST4*a*c) >= 0);
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
			
			// TODO Hit obj
			// Loop objs
			// Which type?
			// Dist and which closest?
			if (hit_sphere(scene->objects, &current_ray))
				colour = 1;
			else
				colour = background(&(scene->camera), current_ray.direction.y);
			
			mlx_put_pixel(mlx->img, pixel.x, pixel.y, colour);
			pixel.x++;
		}
		pixel.y++;
	}
}
