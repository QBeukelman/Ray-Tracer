/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_ambient_light.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 19:31:43 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/02/07 22:47:36 by hesmolde      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static	bool build_ambi(t_scene *scene, char **tokens)
{
	if (!parse_point_value(&(scene->ambi.ratio), tokens[1]) \
		|| !parse_color(&(scene->ambi.color), tokens[2]))
	{
		return (FAILURE);
	}
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
	{
		return (FAILURE);
	}
	return (SUCCESS);
}
