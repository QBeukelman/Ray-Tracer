/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_ambient_light.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 19:31:43 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/25 22:05:59 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_ambi	*build_ambi(char **tokens)
{
	t_ambi		*ambi;

	ambi = safe_malloc(sizeof(t_ambi), "build_ambi()");
	ambi->type = AMBIENT_LIGHT;
	ambi->ambi_ratio = parse_point_value(tokens[1]);
	ambi->color = parse_color(tokens[2]);
	return (ambi);
}

bool	add_ambient_light(t_scene *scene, char **tokens)
{
	if (count_tokens(tokens) != TOKEN_COUNT_A)
		exit_with_message(E_TOKEN_COUNT, objects_to_name(AMBIENT_LIGHT), X_FAILURE);
	scene->ambi = build_ambi(tokens);
	return (SUCCESS);
}
