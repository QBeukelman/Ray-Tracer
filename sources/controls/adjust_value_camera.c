/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adjust_value_camera.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/03 13:41:14 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 19:13:02 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	adjust_position_camera(t_camera *camera, t_edit edit, int delta)
{
	if (edit.editing_vec == V_X)
	{
		camera->position.x += delta;
		camera->position.x = round(camera->position.x);
	}
	else if (edit.editing_vec == V_Y)
	{
		camera->position.y += delta;
		camera->position.y = round(camera->position.y);
	}
	else if (edit.editing_vec == V_Z)
	{
		camera->position.z += delta;
		camera->position.z = round(camera->position.z);
	}
}

void	adjust_value_camera(t_scene *scene, int delta)
{
	if (scene->edit.editing_prop == O_POSITION)
		adjust_position_camera(&scene->camera, scene->edit, delta);
	if (scene->edit.editing_prop == O_CAMERA_PITCH)
		scene->camera.pitch += delta;
	if (scene->edit.editing_prop == O_CAMERA_YAW)
		scene->camera.yaw += delta;
	if (scene->edit.editing_prop == O_CAMERA_FOV)
	{
		scene->camera.fov += delta;
		initialize_rays(scene);
	}
}
