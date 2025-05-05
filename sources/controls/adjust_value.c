/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adjust_value.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 21:18:24 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 18:32:29 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define DISPATCH_TABLE_SIZE 12

typedef struct s_adjust_entry {
	e_object	object_type;
	e_edit		property_type;
	void	(*func)(t_object *obj, t_edit edit, double delta);
} t_adjust_entry;

static void	adjust_position(t_object *object, t_edit edit, double delta)
{
	if (edit.editing_vec == V_X)
	{
		object->position.x += delta;
		object->position.x = round(object->position.x);
	}
	else if (edit.editing_vec == V_Y)
	{
		object->position.y += delta;
		object->position.y = round(object->position.y);
	}
	else if (edit.editing_vec == V_Z)
	{
		object->position.z += delta;
		object->position.z = round(object->position.z);
	}
}

static void	adjust_orientation(t_object *object, t_edit edit, double delta)
{
	if (edit.editing_vec == V_X)
	{
		object->orientation.x += delta;
		object->orientation.x = in_range(object->orientation.x, -1.0, 1.0);
	}
	else if (edit.editing_vec == V_Y)
	{
		object->orientation.y += delta;
		object->orientation.y = in_range(object->orientation.y, -1.0, 1.0);
	}
	else if (edit.editing_vec == V_Z)
	{
		object->orientation.z += delta;
		object->orientation.z = in_range(object->orientation.z, -1.0, 1.0);
	}
}

static void	adjust_radius(t_object *object, t_edit edit, double delta)
{
	(void)edit;
	object->radius += (int)delta;
	object->radius = in_range(round(object->radius), 0, DBL_MAX);
}

static void	adjust_height(t_object *object, t_edit edit, double delta)
{
	(void)edit;
	object->height += (int)delta;
	object->height = in_range(round(object->height), 0, DBL_MAX);
}

const t_adjust_entry	*fill_dispatch_table()
{
	static const t_adjust_entry	dispatch_table[] = {
	
	{SPHERE, O_POSITION, adjust_position},
	{SPHERE, O_DIAMETER, adjust_radius},

	{PLANE, O_POSITION, adjust_position},
	{PLANE, O_ORIENTATION, adjust_orientation},
	
	{CYLINDER, O_POSITION, adjust_position},
	{CYLINDER, O_ORIENTATION, adjust_orientation},
	{CYLINDER, O_DIAMETER, adjust_radius},
	{CYLINDER, O_HEIGHT, adjust_height},
	
	{CONE, O_POSITION, adjust_position},
	{CONE, O_ORIENTATION, adjust_orientation},
	{CONE, O_DIAMETER, adjust_radius},
	{CONE, O_HEIGHT, adjust_height},
	};
	return (dispatch_table);
}

static void adjust_value_object(t_scene *scene, double delta)
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
	double		delta;

	(void)mlx_data;
	if (scene->index_selected == 2)
		scene->edit.editing_prop = O_LIGHT_AMBI_RATIO;
	
	if (scene->edit.editing_prop == O_ORIENTATION || scene->edit.editing_prop == O_LIGHT_AMBI_RATIO)
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

void down_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	double		delta;

	(void)mlx_data;
	if (scene->index_selected == 2)
		scene->edit.editing_prop = O_LIGHT_AMBI_RATIO;
	
	if (scene->edit.editing_prop == O_ORIENTATION || scene->edit.editing_prop == O_LIGHT_AMBI_RATIO)
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
