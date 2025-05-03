/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   select_property.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 19:08:13 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/03 14:18:44 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	increment_sphere_property(t_scene *scene)
{
	if (scene->edit.editing_prop == O_POSITION)
		scene->edit.editing_prop = O_DIAMETER;
	else
		scene->edit.editing_prop = O_POSITION;
}

void	increment_plane_property(t_scene *scene)
{
	if (scene->edit.editing_prop == O_POSITION)
		scene->edit.editing_prop = O_ORIENTATION;
	else
		scene->edit.editing_prop = O_POSITION;
}

void	increment_cylinder_property(t_scene *scene)
{
	if (scene->edit.editing_prop == O_POSITION)
		scene->edit.editing_prop = O_ORIENTATION;
	else if (scene->edit.editing_prop == O_ORIENTATION)
		scene->edit.editing_prop = O_DIAMETER;
	else if (scene->edit.editing_prop == O_DIAMETER)
		scene->edit.editing_prop = O_HEIGHT;
	else if (scene->edit.editing_prop == O_HEIGHT)
		scene->edit.editing_prop = O_POSITION;
}

void	increment_camera_property(t_scene *scene)
{
	if (scene->edit.editing_prop == O_POSITION)
		scene->edit.editing_prop = O_CAMERA_PITCH;
	else if (scene->edit.editing_prop == O_CAMERA_PITCH)
		scene->edit.editing_prop = O_CAMERA_YAW;
	else if (scene->edit.editing_prop == O_CAMERA_YAW)
		scene->edit.editing_prop = O_CAMERA_FOV;
	else if (scene->edit.editing_prop == O_CAMERA_FOV)
		scene->edit.editing_prop = O_POSITION;
	anounce_selection(scene);
}

void	tab_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	t_object *selected_object;

	selected_object = NULL;
	if (scene->index_selected == 0)
		increment_camera_property(scene);

	if (scene->index_selected >= 3)
		selected_object = obj_for_index(scene->objects, scene->index_selected);
	if (selected_object == NULL)
		return ;

	if (selected_object->type == SPHERE)
		increment_sphere_property(scene);
	if (selected_object->type == PLANE)
		increment_plane_property(scene);
	else if (selected_object->type == CYLINDER)
		increment_cylinder_property(scene);

	anounce_selection(scene);
}

