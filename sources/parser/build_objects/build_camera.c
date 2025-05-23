/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_camera.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/25 22:22:28 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/07 12:45:08 by hesmolde      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static void	set_yaw_pitch(t_vector orientation, int *yaw, int *pitch)
{
	orientation = vec_normalize(orientation);
	*yaw = radians_to_degrees(atan2(orientation.x, -orientation.z));
	*pitch = radians_to_degrees(asin(orientation.y));
}

static bool	build_camera(t_scene *scene, char **tokens)
{
	t_vector	orientation;

	if (!parse_position(&(scene->camera.position), tokens[1], 0.0) \
		|| !parse_position(&orientation, tokens[2], 1.0)
		|| !parse_int(&(scene->camera.fov), tokens[3]))
	{
		return (FAILURE);
	}
	set_yaw_pitch(orientation, &(scene->camera.yaw), &(scene->camera.pitch));
	scene->camera.type = CAMERA;
	return (SUCCESS);
}

bool	add_camera(t_scene *scene, char **tokens)
{
	if (scene->camera.initialized)
	{
		show_error(E_DUP_OBJ, objects_to_name(CAMERA));
		return (FAILURE);
	}
	if (count_tokens(tokens) != TOKEN_COUNT_C)
	{
		show_error(E_TOKEN_COUNT, objects_to_name(CAMERA));
		return (FAILURE);
	}
	if (build_camera(scene, tokens) == false)
		return (FAILURE);
	scene->camera.initialized = true;
	return (SUCCESS);
}
