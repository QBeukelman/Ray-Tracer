/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:18:24 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/05/07 11:27:25 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define DISPATCH_TABLE_SIZE 12

const t_adjust_entry	*fill_dispatch_table(void)
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

void	adjust_value_object(t_scene *scene, double delta)
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
		if (dispatch_table[i].object_type == selected_object->type
			&& dispatch_table[i].property_type == scene->edit.editing_prop)
		{
			dispatch_table[i].func(selected_object, scene->edit, delta);
			return ;
		}
		i++;
	}
}
