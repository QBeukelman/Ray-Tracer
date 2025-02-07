/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_ambient_light.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 19:31:43 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/02/07 02:02:36 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

// static t_ambi	*build_ambi(char **tokens)
// {
// 	t_ambi		*ambi;
// 	float		ambi_ratio;
// 	t_color		*color;

// 	ambi = malloc(sizeof(t_ambi));
// 	if (ambi == NULL)
// 	{
// 		show_error(E_MALLOC, "build_ambi()");
// 		return (NULL);	
// 	}
// 	ambi->type = AMBIENT_LIGHT;
// 	ambi_ratio = parse_point_value(tokens[1]);
// 	if (ambi_ratio == NAN)
// 		return (NULL);
// 	ambi->ambi_ratio = ambi_ratio;
// 	color = parse_color(tokens[2]);
// 	if (color == NULL)
// 		return (NULL);
// 	ambi->color = color;
// 	return (ambi);
// }

// bool	add_ambient_light(t_scene *scene, char **tokens)
// {
// 	t_ambi		*ambi;
	
// 	if (count_tokens(tokens) != TOKEN_COUNT_A)
// 	{
// 		show_error(E_TOKEN_COUNT, objects_to_name(AMBIENT_LIGHT));
// 		return (FAILURE);
// 	}
// 	ambi = build_ambi(tokens);
// 	if (ambi == NULL)
// 		return (FAILURE);
// 	scene->ambi = ambi;
// 	return (SUCCESS);
// }
