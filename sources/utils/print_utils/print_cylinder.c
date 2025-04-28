/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_cylinder.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 16:36:10 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/29 00:58:07 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static void	print_label(const char *label, bool is_hilighted)
{
	if (is_hilighted)
		printf(C_YELLOW);
	printf("\t%s\n", label);
	printf(RESET_COLOR);
}

static void	print_value(float value, bool is_hilighted)
{
	if (is_hilighted)
		printf(C_YELLOW);
	printf("\t\t%.1f\n", value);
	printf(RESET_COLOR);
}

void	print_cylinder(t_object *object, t_edit edit)
{
	printf("[%d] Cylinder\n", object->index);

	// Position
	print_label("Pos:", edit.editing_prop == O_POSITION);
	print_value(object->position.x, edit.editing_prop == O_POSITION && edit.editing_vec == V_X);
	print_value(object->position.y, edit.editing_prop == O_POSITION && edit.editing_vec == V_Y);
	print_value(object->position.z, edit.editing_prop == O_POSITION && edit.editing_vec == V_Z);
	printf("\n");

	// Axis / Orientation
	print_label("Orientation:", edit.editing_prop == O_ORIENTATION);
	print_value(object->orientation.x, edit.editing_prop == O_ORIENTATION && edit.editing_vec == V_X);
	print_value(object->orientation.y, edit.editing_prop == O_ORIENTATION && edit.editing_vec == V_Y);
	print_value(object->orientation.z, edit.editing_prop == O_ORIENTATION && edit.editing_vec == V_Z);
	printf("\n");

	// Diamater
	print_label("Diameter:", edit.editing_prop == O_DIAMETER);
	print_value(object->diameter, edit.editing_prop == O_DIAMETER);
	printf("\n");

	// Height
	print_label("height:", edit.editing_prop == O_HEIGHT);
	print_value(object->diameter, edit.editing_prop == O_HEIGHT);
	printf("\n");
}
