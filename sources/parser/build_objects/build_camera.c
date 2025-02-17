/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_camera.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/25 22:22:28 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/02/17 23:29:44 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static bool	build_camera(t_scene *scene, char **tokens)
{
	if (!parse_position(&(scene->camera.position), tokens[1], 0.0) \
		|| !parse_position(&(scene->camera.orientation), tokens[2], 1.0)
		|| !parse_int(&(scene->camera.fov), tokens[3]))
	{
		return (FAILURE);
	}
	scene->camera.type = CAMERA;
	return (SUCCESS);
}

bool	add_camera(t_scene *scene, char **tokens)
{
	if (count_tokens(tokens) != TOKEN_COUNT_C)
	{
		show_error(E_TOKEN_COUNT, objects_to_name(CAMERA));
		return (FAILURE);
	}
	if (build_camera(scene, tokens) == false)
		return (FAILURE);
	return (SUCCESS);
}
