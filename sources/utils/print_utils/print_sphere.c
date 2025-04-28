/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 22:55:41 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/28 23:03:49 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	print_sphere(t_object *object, t_edit edit)
{
	printf("[%d] Sphere\n", object->index);
	
	// Position
	if (edit.editing_prop == O_POSITION)
		printf(C_YELLOW);
	printf("\tPos: \n");
	printf(RESET_COLOR);

	if (edit.editing_prop == O_POSITION && edit.editing_vec == V_X)
		printf(C_YELLOW);
	printf("\t\t%.1f\n", object->position.x);
	printf(RESET_COLOR);
	if (edit.editing_prop == O_POSITION && edit.editing_vec == V_Y)
		printf(C_YELLOW);
	printf("\t\t%.1f\n", object->position.y);
	printf(RESET_COLOR);
	if (edit.editing_prop == O_POSITION && edit.editing_vec == V_Z)
		printf(C_YELLOW);
	printf("\t\t%.1f\n\n", object->position.z);
	printf(RESET_COLOR);
	
	// Diamater
	if (edit.editing_prop == O_DIAMETER)
		printf(C_YELLOW);
	printf("\tDiam: \n\t\t%.1f\n", object->diameter);
	printf(RESET_COLOR);
}