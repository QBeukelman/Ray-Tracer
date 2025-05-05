/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_plane.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 22:59:51 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 21:43:54 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	print_plane(t_object *object, t_edit edit)
{
	printf("[%d] Plane\n\n", object->index);
	print_label("Position:", edit.editing_prop == O_POSITION);
	print_value(object->position.x, edit.editing_prop == O_POSITION
		&& edit.editing_vec == V_X, V_X);
	print_value(object->position.y, edit.editing_prop == O_POSITION
		&& edit.editing_vec == V_Y, V_Y);
	print_value(object->position.z, edit.editing_prop == O_POSITION
		&& edit.editing_vec == V_Z, V_Z);
	printf("\n");
	print_label("Orientation:", edit.editing_prop == O_ORIENTATION);
	print_value(object->orientation.x, edit.editing_prop == O_ORIENTATION
		&& edit.editing_vec == V_X, V_X);
	print_value(object->orientation.y, edit.editing_prop == O_ORIENTATION
		&& edit.editing_vec == V_Y, V_Y);
	print_value(object->orientation.z, edit.editing_prop == O_ORIENTATION
		&& edit.editing_vec == V_Z, V_Z);
}
