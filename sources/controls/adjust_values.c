/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adjust_values.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 19:04:11 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 19:05:23 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	adjust_position(t_object *object, t_edit edit, double delta)
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

void	adjust_orientation(t_object *object, t_edit edit, double delta)
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

void	adjust_radius(t_object *object, t_edit edit, double delta)
{
	(void)edit;
	object->radius += (int)delta;
	object->radius = in_range(round(object->radius), 0, DBL_MAX);
}

void	adjust_height(t_object *object, t_edit edit, double delta)
{
	(void)edit;
	object->height += (int)delta;
	object->height = in_range(round(object->height), 0, DBL_MAX);
}
