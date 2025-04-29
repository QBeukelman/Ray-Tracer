/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adjust_value.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 21:18:24 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/29 21:55:41 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

typedef struct s_adjust_entry {
	int		object_type;
	int		property_type;
	void	(*func)(t_object *obj, t_edit edit, int delta);
} t_adjust_entry;

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

const t_adjust_entry	*fill_dispatch_table()
{
	static const t_adjust_entry	dispatch_table[] = {
	{CAMERA, O_POSITION, adjust_position},
	{CAMERA, O_ORIENTATION, adjust_orientation},

	{LIGHT, O_POSITION, adjust_position},

	{SPHERE, O_POSITION, adjust_position},
	{SPHERE, O_DIAMETER, (void *)adjust_diameter},

	{PLANE, O_POSITION, adjust_position},
	{PLANE, O_ORIENTATION, adjust_orientation},

	{CYLINDER, O_POSITION, adjust_position},
	{CYLINDER, O_ORIENTATION, adjust_orientation},
	{CYLINDER, O_DIAMETER, (void *)adjust_diameter},
	{CYLINDER, O_HEIGHT, (void *)adjust_height},
	};
	return (dispatch_table);
}

void adjust_value(t_scene *scene, int delta)
{
	t_object *selected_object = obj_for_index(scene->objects, scene->index_selected);
	int obj_type = selected_object->type;
	int prop_type = scene->edit.editing_prop;
	const t_adjust_entry *dispatch_table = fill_dispatch_table();
	
	for (size_t i = 0; i < (sizeof(*dispatch_table) / sizeof(dispatch_table[0])); i++)
	{
		if (dispatch_table[i].object_type == obj_type &&
			dispatch_table[i].property_type == prop_type)
		{
			dispatch_table[i].func(selected_object, scene->edit, delta);
			return;
		}
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
