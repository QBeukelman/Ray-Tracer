/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adjust_value.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 21:18:24 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/03 14:24:04 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define DISPATCH_TABLE_SIZE 12

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

static void	adjust_diameter(t_object *object, t_edit edit, int delta)
{
	(void)edit;
	object->diameter += delta;
}

static void	adjust_height(t_object *object, t_edit edit, int delta)
{
	(void)edit;
	object->height += delta;
}

const t_adjust_entry	*fill_dispatch_table()
{
	static const t_adjust_entry	dispatch_table[] = {
	
	{SPHERE, O_POSITION, adjust_position},
	{SPHERE, O_DIAMETER, adjust_diameter},

	{PLANE, O_POSITION, adjust_position},
	{PLANE, O_ORIENTATION, adjust_orientation},
	
	{CYLINDER, O_POSITION, adjust_position},
	{CYLINDER, O_ORIENTATION, adjust_orientation},
	{CYLINDER, O_DIAMETER, adjust_diameter},
	{CYLINDER, O_HEIGHT, adjust_height},
	
	{CONE, O_POSITION, adjust_position},
	{CONE, O_ORIENTATION, adjust_orientation},
	{CONE, O_DIAMETER, adjust_diameter},
	{CONE, O_HEIGHT, adjust_height},
	};
	return (dispatch_table);
}

static void adjust_value_object(t_scene *scene, int delta)
{
	int						i;
	t_object				*selected_object;
	const t_adjust_entry	*dispatch_table;

	selected_object = obj_for_index(scene->objects, scene->index_selected);
	if (selected_object == NULL)
		return ;
	dispatch_table = fill_dispatch_table();
	
	i = 0;
	while (i < DISPATCH_TABLE_SIZE)
	{
		if (dispatch_table[i].object_type == selected_object->type &&
			dispatch_table[i].property_type == scene->edit.editing_prop)
		{
			dispatch_table[i].func(selected_object, scene->edit, delta);
			return ;
		}
		i++;
	}
}

void	up_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	if (scene->index_selected <= 2)
	{
		// TODO: Value for non Objects
		if (scene->index_selected == 0)
			adjust_value_camera(scene, 1);
	}
	else
	{
		adjust_value_object(scene, 1);
	}
	anounce_selection(scene);
}

void down_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	if (scene->index_selected <= 2)
	{
		// TODO: Value for non Objects
		if (scene->index_selected == 0)
			adjust_value_camera(scene, -1);
	}
	else
	{
		adjust_value_object(scene, -1);
	}
	anounce_selection(scene);
}
