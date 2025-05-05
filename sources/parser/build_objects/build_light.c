/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_light.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 12:50:34 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/05/05 17:55:03 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static bool	build_light(t_scene *scene, char **tokens)
{
	if (!parse_position(&(scene->light.position), tokens[1], 0.0) \
		|| !parse_point_value(&(scene->light.brightness), tokens[2]))
	{
		return (FAILURE);
	}
	scene->light.type = LIGHT;
	return (SUCCESS);
}

bool	add_light(t_scene *scene, char **tokens)
{
	if (scene->light.initialized)
	{
		show_error(E_DUP_OBJ, objects_to_name(LIGHT));
		return (FAILURE);
	}
	if (count_tokens(tokens) != TOKEN_COUNT_L)
	{
		show_error(E_TOKEN_COUNT, objects_to_name(LIGHT));
		return (FAILURE);
	}
	if (build_light(scene, tokens) == false)
		return (FAILURE);
	scene->light.initialized = true;
	return (SUCCESS);
}
