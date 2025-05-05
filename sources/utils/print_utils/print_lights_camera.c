/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_lights_camera.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/29 21:47:28 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 20:00:30 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	print_camera(t_camera camera, t_edit edit)
{
	printf("[%d] Camera\n\n", 0);
	print_label("Position:", edit.editing_prop == O_POSITION);
	print_value(camera.position.x, edit.editing_prop == O_POSITION
		&& edit.editing_vec == V_X, V_X);
	print_value(camera.position.y, edit.editing_prop == O_POSITION
		&& edit.editing_vec == V_Y, V_Y);
	print_value(camera.position.z, edit.editing_prop == O_POSITION
		&& edit.editing_vec == V_Z, V_Z);
	printf("\n");
	print_label("Orientation:", edit.editing_prop == O_CAMERA_PITCH
		|| edit.editing_prop == O_CAMERA_YAW);
	if (edit.editing_prop == O_CAMERA_PITCH)
		printf(C_MAGENTA);
	printf("\t\tpitch: %d\n", camera.pitch);
	printf(RESET_COLOR);
	if (edit.editing_prop == O_CAMERA_YAW)
		printf(C_MAGENTA);
	printf("\t\tyaw: %d\n\n", camera.yaw);
	printf(RESET_COLOR);
	print_label("Field of View:", edit.editing_prop == O_CAMERA_FOV);
	if (edit.editing_prop == O_CAMERA_FOV)
		printf(C_MAGENTA);
	printf("\t\tint: %d\n", camera.fov);
	printf(RESET_COLOR);
}

void	print_light(t_light light, t_edit edit)
{
	printf("[%d] Point Light\n\n", 1);
	print_label("Position:", edit.editing_prop == O_POSITION);
	print_value(light.position.x, edit.editing_prop == O_POSITION
		&& edit.editing_vec == V_X, V_X);
	print_value(light.position.y, edit.editing_prop == O_POSITION
		&& edit.editing_vec == V_Y, V_Y);
	print_value(light.position.z, edit.editing_prop == O_POSITION
		&& edit.editing_vec == V_Z, V_Z);
	printf("\n");
}

void	print_ambi(t_ambi ambi)
{
	printf("[%d] Ambient Light\n\n", 2);
	printf(C_MAGENTA);
	printf("\tAmbient Light Ratio:\n");
	printf("\t\tf: %.1f\n", ambi.ratio);
	printf(RESET_COLOR);
}
