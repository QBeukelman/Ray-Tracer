/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 22:55:41 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 20:11:03 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	print_sphere(t_object *object, t_edit edit)
{
	printf("[%d] Sphere\n\n", object->index);
	print_label("Position:", edit.editing_prop == O_POSITION);
	print_value(object->position.x, edit.editing_prop == O_POSITION
		&& edit.editing_vec == V_X, V_X);
	print_value(object->position.y, edit.editing_prop == O_POSITION
		&& edit.editing_vec == V_Y, V_Y);
	print_value(object->position.z, edit.editing_prop == O_POSITION
		&& edit.editing_vec == V_Z, V_Z);
	printf("\n");
	print_label("Radius:", edit.editing_prop == O_DIAMETER);
	print_value(object->radius, edit.editing_prop == O_DIAMETER, V_NONE);
	printf("\n");
}
