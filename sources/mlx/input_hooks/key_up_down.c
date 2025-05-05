/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_up_down.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 19:09:13 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 19:09:33 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	up_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	double		delta;

	(void)mlx_data;
	if (scene->index_selected == 2)
		scene->edit.editing_prop = O_LIGHT_AMBI_RATIO;
	if (scene->edit.editing_prop == O_ORIENTATION
		|| scene->edit.editing_prop == O_LIGHT_AMBI_RATIO)
		delta = 0.1;
	else
		delta = 1;
	if (scene->index_selected <= 2)
	{
		if (scene->index_selected == 0)
			adjust_value_camera(scene, delta);
		if (scene->index_selected == 1)
			adjust_value_point_light(scene, delta);
		if (scene->index_selected == 2)
			adjust_value_ambi_light(scene, delta);
	}
	else
	{
		adjust_value_object(scene, delta);
	}
	anounce_selection(scene);
}

void	down_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	double		delta;

	(void)mlx_data;
	if (scene->index_selected == 2)
		scene->edit.editing_prop = O_LIGHT_AMBI_RATIO;
	if (scene->edit.editing_prop == O_ORIENTATION
		|| scene->edit.editing_prop == O_LIGHT_AMBI_RATIO)
		delta = -0.1;
	else
		delta = -1;
	if (scene->index_selected <= 2)
	{
		if (scene->index_selected == 0)
			adjust_value_camera(scene, delta);
		if (scene->index_selected == 1)
			adjust_value_point_light(scene, delta);
		if (scene->index_selected == 2)
			adjust_value_ambi_light(scene, delta);
	}
	else
	{
		adjust_value_object(scene, delta);
	}
	anounce_selection(scene);
}
