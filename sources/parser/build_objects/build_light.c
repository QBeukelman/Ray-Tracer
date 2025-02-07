/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:50:34 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/02/07 13:16:19 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_light	*build_light(char **tokens)
{
	t_light		*light;
	t_vect		*position;
	float		brightness;

	light = malloc(sizeof(t_light));
	if (light == NULL)
	{
		show_error(E_MALLOC, "build_light()");
		return (NULL);
	} 
	light->type = LIGHT;
	position = parse_position(tokens[1], 0.0);
	if (position == NULL)
		return (NULL);
	light->position = position;
	brightness = parse_point_value(tokens[2]);
	if (brightness == NAN)
		return (NULL);
	light->brightness = brightness;
	return (light);
}

bool add_light(t_scene *scene, char **tokens)
{
	t_light		*light;
	
	if (count_tokens(tokens) != TOKEN_COUNT_L)
	{
		show_error(E_TOKEN_COUNT, objects_to_name(LIGHT));
		return (FAILURE);
	}
	if (scene->light != NULL)
	{
		show_error(E_OBJ_COUNT, objects_to_name(AMBIENT_LIGHT));
		return (FAILURE);
	}
	light = build_light(tokens);
	if (light == NULL)
		return (FAILURE);
	scene->light = light;
	return (SUCCESS);
}
