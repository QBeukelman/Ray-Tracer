/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_ambient_light.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 19:31:43 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/28 10:25:25 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static bool	build_ambi(t_scene *scene, char **tokens)
{
	if (!parse_point_value(&(scene->ambi.ratio), tokens[1]) \
		|| !parse_colour(&(scene->ambi.colour), tokens[2]))
		return (FAILURE);
	scene->ambi.type = AMBIENT_LIGHT;
	return (SUCCESS);
}

bool	add_ambient_light(t_scene *scene, char **tokens)
{
	if (count_tokens(tokens) != TOKEN_COUNT_A)
	{
		show_error(E_TOKEN_COUNT, objects_to_name(AMBIENT_LIGHT));
		return (FAILURE);
	}
	if (build_ambi(scene, tokens) == false)
		return (FAILURE);
	scene->ambi.index = INDEX_AMBI;
	scene->ambi.initialized = true;
	return (SUCCESS);
}
