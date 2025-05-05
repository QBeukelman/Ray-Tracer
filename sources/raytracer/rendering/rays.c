/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/09 00:11:22 by hein          #+#    #+#                 */
/*   Updated: 2025/05/04 16:23:45 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

#define RADIAN_CONST 0.0174533

static t_vector	**allocate_rays()
{
	t_vector	**rays;
	int			y;

	rays = (t_vector **)malloc(HEIGHT * sizeof(t_vector *));
	if (rays == NULL)
	{
		return (NULL);
	}
	rays[0] = (t_vector *)malloc(WIDTH * HEIGHT * sizeof(t_vector));
	if (rays[0] == NULL)
	{
		free (rays);
		return (NULL);
	}
	y = 1;
	while (y < HEIGHT)
	{
		rays[y] = rays[0] + (y * WIDTH);
		y++;
	}
	return (rays);
}

static void	generate_rays(t_vector **rays, t_camera *c)
{
	const double	aspect_ratio = (double)WIDTH / (double)HEIGHT; 
	const double	fov_radians = tan((c->fov * RADIAN_CONST) / 2);
	t_pixel			p;
	t_vector		worldpixel;
	
	p.y = 0;
	while (p.y < HEIGHT)
	{
		p.x = 0;
		while (p.x < WIDTH)
		{
			p.ndc_x = (p.x + 0.5) / WIDTH;
			p.ndc_y = (p.y + 0.5) / HEIGHT;
			p.camera_x = ((2 * p.ndc_x) - 1) * aspect_ratio;
			p.camera_y = (1 - (2 * p.ndc_y));
			p.camera_x *= fov_radians;
			p.camera_y *= fov_radians;
			worldpixel = vec_set(p.camera_x, p.camera_y, -1);
			rays[p.y][p.x] = vec_normalize(worldpixel);
			p.x++;
		}
		p.y++;
	}
}

bool	initialize_rays(t_scene *scene)
{
	if (scene->rays == NULL)
		scene->rays = allocate_rays();
	if (scene->rays == NULL)
		return (false);
	generate_rays(scene->rays, &(scene->camera));
	return (true);
}
