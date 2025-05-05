/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_cylinder.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 16:36:10 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/04 16:50:47 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	print_cylinder(t_object *object, t_edit edit)
{
	printf("[%d] Cyliner\n\n", object->index);

	// Position
	print_label("Position:", edit.editing_prop == O_POSITION);
	print_value(object->position.x, edit.editing_prop == O_POSITION && edit.editing_vec == V_X, V_X);
	print_value(object->position.y, edit.editing_prop == O_POSITION && edit.editing_vec == V_Y, V_Y);
	print_value(object->position.z, edit.editing_prop == O_POSITION && edit.editing_vec == V_Z, V_Z);
	printf("\n");

	// Axis / Orientation
	print_label("Orientation:", edit.editing_prop == O_ORIENTATION);
	print_value(object->orientation.x, edit.editing_prop == O_ORIENTATION && edit.editing_vec == V_X, V_X);
	print_value(object->orientation.y, edit.editing_prop == O_ORIENTATION && edit.editing_vec == V_Y, V_Y);
	print_value(object->orientation.z, edit.editing_prop == O_ORIENTATION && edit.editing_vec == V_Z, V_Z);
	printf("\n");

	// Radius
	print_label("Radius:", edit.editing_prop == O_DIAMETER);
	print_value(object->radius, edit.editing_prop == O_DIAMETER, V_NONE);
	printf("\n");

	// Height
	print_label("height:", edit.editing_prop == O_HEIGHT);
	print_value(object->height, edit.editing_prop == O_HEIGHT, V_NONE);
	printf("\n");
}
