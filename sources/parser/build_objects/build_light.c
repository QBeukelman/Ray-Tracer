/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:50:34 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/01/10 13:08:10 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_light	*build_light(char **tokens)
{
	t_light		*light;

	light = safe_malloc(sizeof(t_light), "build_light()");
	light->type = LIGHT;
	light->position = parse_position(tokens[1], 0.0);
	light->brightness = parse_point_value(tokens[2]);
	return (light);
}

bool add_light(t_scene *scene, char **tokens)
{
	if (count_tokens(tokens) != TOKEN_COUNT_L)
		exit_with_message(E_TOKEN_COUNT, objects_to_name(LIGHT), \
			X_FAILURE);
	scene->light = build_light(tokens);
	return (SUCCESS);
}
