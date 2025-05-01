/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_lights_camera.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/29 21:47:28 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/30 21:30:32 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	print_camera(t_camera camera, t_edit edit)
{
	printf("[%d] Camera\n", 0);

	// Position
	print_label("Pos:", edit.editing_prop == O_POSITION);
	print_value(camera.position.x, edit.editing_prop == O_POSITION && edit.editing_vec == V_X);
	print_value(camera.position.y, edit.editing_prop == O_POSITION && edit.editing_vec == V_Y);
	print_value(camera.position.z, edit.editing_prop == O_POSITION && edit.editing_vec == V_Z);
	printf("\n");

	// Axis / Orientation
	print_label("Orientation:", edit.editing_prop == O_ORIENTATION);
	// TODO: Implement orientation
	printf("\n");
}

void	print_light(t_light light, t_edit edit)
{
	printf("[%d] Light\n", 1);

	// Position
	print_label("Pos:", edit.editing_prop == O_POSITION);
	print_value(light.position.x, edit.editing_prop == O_POSITION && edit.editing_vec == V_X);
	print_value(light.position.y, edit.editing_prop == O_POSITION && edit.editing_vec == V_Y);
	print_value(light.position.z, edit.editing_prop == O_POSITION && edit.editing_vec == V_Z);
	printf("\n");
}

void	print_ambi(t_ambi ambi)
{
	printf("[%d] Light\n", 2);
	printf("\n");
}
