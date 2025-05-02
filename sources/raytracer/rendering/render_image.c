/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_image.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 15:15:23 by hein          #+#    #+#                 */
/*   Updated: 2025/05/02 13:43:54 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

// bool collision_for_object(t_object *object, t_ray ray, t_collision *collision)
// {
// 	const t_collision_func f[3] = {sphere_collision, plane_collision, cylinder_collision};
// 	switch (object->type)
// 	{
// 		case SPHERE:
// 			return (sphere_collision(object, ray, collision));
// 		case PLANE:
// 			return (plane_collision(object, ray, collision));
// 		default:
// 			return (0);
// 	}
// 	return (0);
// }

bool is_collision(t_object *objects, t_ray ray, t_collision *collision)
{
	const t_collision_func f[3] = {sphere_collision, plane_collision, cylinder_collision};
	t_object				*current_object;
	t_collision				temp_collision;
	bool					found_collision;
	double					min_distance;

	found_collision = false;
	min_distance = __DBL_MAX__;
	temp_collision.distance = min_distance;
	current_object = objects;
	while (current_object)
	{
		if (f[current_object->type - 3](current_object, ray, &temp_collision) &&
			temp_collision.distance > 0 &&
			temp_collision.distance < min_distance)
		{
			min_distance = temp_collision.distance;
			*collision = temp_collision;
			found_collision = true;
		}
		current_object = current_object->next;
	}
	return (found_collision);
}

void	render_image(t_mlx_data *mlx, t_scene *scene)
{
	t_pixel			p;
	t_ray			ray;
	int				color;
	t_collision		collision;
	const t_matrix	matrix = set_translation_matrix(scene->camera.yaw, -scene->camera.pitch);

	p.y = 0;
	while (p.y < HEIGHT)
	{
		p.x = 0;
		while (p.x < WIDTH)
		{
			ray.direction = set_ray_direction(scene->rays[p.y][p.x], matrix);
			ray.origin = scene->camera.position;
			if (is_collision(scene->objects, ray, &collision))
				color = calculate_shading(&collision, &(scene->light), &(scene->ambi), scene->objects);
			else
				color = 0XFF;
			mlx_put_pixel(mlx->img, p.x, p.y, color);
			p.x++;
		}
		p.y++;
	}
}
