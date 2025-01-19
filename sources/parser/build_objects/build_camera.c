/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:22:28 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/01/19 15:51:41 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_camera		*build_camera(char **tokens)
{
	t_camera	*camera;
	t_vect		*position;
	t_vect		*orientation;
	int			fov;

	camera = malloc(sizeof(t_camera));
	if (camera == NULL)
	{
		show_error(E_MALLOC, "build_camera()");
		return (NULL);
	}
	camera->type = CAMERA;
	position = parse_position(tokens[1], 0.0);
	if (position == NULL)
		return (NULL);
	camera->position = position;
	orientation = parse_position(tokens[2], 1.0);
	if (orientation == NULL)
		return (NULL);
	camera->orientation = orientation;
	fov = parse_int(tokens[3], 180);
	if (fov < 0)
		return (NULL);
	camera->fov = fov;
	return (camera);
}

bool	add_camera(t_scene *scene, char **tokens)
{
	t_camera	*camera;
	
	if (count_tokens(tokens) != TOKEN_COUNT_C)
	{
		show_error(E_TOKEN_COUNT, objects_to_name(CAMERA));
		return (FAILURE);
	}
	camera = build_camera(tokens);
	if (camera == NULL)
		return (FAILURE);
	scene->camera = camera;
	return (SUCCESS);
}
