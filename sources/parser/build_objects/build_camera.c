/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_camera.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/25 22:22:28 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/26 00:32:22 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_camera		*build_camera(char **tokens)
{
	t_camera	*camera;

	camera = safe_malloc(sizeof(t_camera), "build_camera()");
	camera->type = CAMERA;
	camera->position = parse_position(tokens[1]);

	return (camera);
}

bool	add_camera(t_scene *scene, char **tokens)
{
	if (count_tokens(tokens) != TOKEN_COUNT_C)
		exit_with_message(E_TOKEN_COUNT, objects_to_name(CAMERA), X_FAILURE);
	scene->camera = build_camera(tokens);
	return (SUCCESS);
}
