/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adjust_value.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 21:18:24 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/29 00:53:06 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	adjust_position(t_object *object, t_edit edit, int delta)
{
	if (edit.editing_vec == V_X)
		object->position.x += delta;
	else if (edit.editing_vec == V_Y)
		object->position.y += delta;
	else if (edit.editing_vec == V_Z)
		object->position.z += delta;
}

static void	adjust_orientation(t_object *object, t_edit edit, int delta)
{
	if (edit.editing_vec == V_X)
		object->orientation.x += delta;
	else if (edit.editing_vec == V_Y)
		object->orientation.y += delta;
	else if (edit.editing_vec == V_Z)
		object->orientation.z += delta;
}

static void	adjust_diameter(t_object *object, int delta)
{
	object->diameter += delta;
}

static void	adjust_height(t_object *object, int delta)
{
	object->height += delta;
}

static void	adjust_value(t_scene *scene, int delta)
{
	t_object *selected_object;

	selected_object = obj_for_index(scene->objects, scene->index_selected);
	printf("Sel: %d\n", selected_object->index);

	if (selected_object->type == SPHERE)
	{
		if (scene->edit.editing_prop == O_POSITION)
			adjust_position(selected_object, scene->edit, delta);
		else if (scene->edit.editing_prop == O_DIAMETER)
			adjust_diameter(selected_object, delta);
	}
	if (selected_object->type == CYLINDER)
	{
		printf("Prop: %d\n", scene->edit.editing_prop);
		if (scene->edit.editing_prop == O_POSITION)
			adjust_position(selected_object, scene->edit, delta);
		else if (scene->edit.editing_prop == O_ORIENTATION)
			adjust_orientation(selected_object, scene->edit, delta);
		else if (scene->edit.editing_prop == O_DIAMETER)
			adjust_diameter(selected_object, delta);
		else if (scene->edit.editing_prop == O_HEIGHT)
			adjust_height(selected_object, delta);
	}
}

void	increment_value(t_mlx_data *mlx_data, t_scene *scene)
{
	adjust_value(scene, 1);
	anounce_selection(scene);
}

void decrement_value(t_mlx_data *mlx_data, t_scene *scene)
{
	adjust_value(scene, -1);
	anounce_selection(scene);
}
