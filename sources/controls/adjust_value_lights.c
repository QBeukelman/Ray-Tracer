/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adjust_value_lights.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/04 16:35:18 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 19:13:22 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	adjust_position_light(t_light *point_light, t_edit edit, int delta)
{
	if (edit.editing_vec == V_X)
	{
		point_light->position.x += delta;
		point_light->position.x = round(point_light->position.x);
	}
	else if (edit.editing_vec == V_Y)
	{
		point_light->position.y += delta;
		point_light->position.y = round(point_light->position.y);
	}
	else if (edit.editing_vec == V_Z)
	{
		point_light->position.z += delta;
		point_light->position.z = round(point_light->position.z);
	}
}

void	adjust_value_point_light(t_scene *scene, int delta)
{
	if (scene->edit.editing_prop == O_POSITION)
		adjust_position_light(&scene->light, scene->edit, delta);
}

void	adjust_value_ambi_light(t_scene *scene, double delta)
{
	scene->ambi.ratio = in_range((scene->ambi.ratio += delta), 0, 1);
}
