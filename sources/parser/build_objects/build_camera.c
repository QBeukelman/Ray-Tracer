/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:22:28 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/01/10 12:10:30 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_camera		*build_camera(char **tokens)
{
	t_camera	*camera;

	camera = safe_malloc(sizeof(t_camera), "build_camera()");
	camera->type = CAMERA;
	camera->position = parse_position(tokens[1], 0.0);
	camera->orientation = parse_position(tokens[2], 1.0);
	camera->fov = parse_int(tokens[3], 180);

	return (camera);
}

bool	add_camera(t_scene *scene, char **tokens)
{
	if (count_tokens(tokens) != TOKEN_COUNT_C)
		exit_with_message(E_TOKEN_COUNT, objects_to_name(CAMERA), X_FAILURE);
	scene->camera = build_camera(tokens);
	return (SUCCESS);
}
