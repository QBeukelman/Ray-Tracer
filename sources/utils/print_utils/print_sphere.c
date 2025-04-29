/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 22:55:41 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/29 20:55:57 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	print_sphere(t_object *object, t_edit edit)
{
	printf("[%d] Sphere\n", object->index);

	// Position
	print_label("Pos:", edit.editing_prop == O_POSITION);
	print_value(object->position.x, edit.editing_prop == O_POSITION && edit.editing_vec == V_X);
	print_value(object->position.y, edit.editing_prop == O_POSITION && edit.editing_vec == V_Y);
	print_value(object->position.z, edit.editing_prop == O_POSITION && edit.editing_vec == V_Z);
	printf("\n");
	
	// Diamater
	print_label("Diameter:", edit.editing_prop == O_DIAMETER);
	print_value(object->diameter, edit.editing_prop == O_DIAMETER);
	printf("\n");
}
