/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:16:02 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/02/15 13:16:04 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_object	*build_cylinder(char **tokens)
{
	t_object		*new;

	new = malloc(sizeof(t_object));
	if (new == NULL)
	{
		show_error(E_MALLOC, "build_cylinder()");
		return (NULL);
	}
	ft_memset(new, 0, sizeof(t_object));
	new->type = CYLINDER;
	if (!parse_position(&(new->position), tokens[1], 0.0) \
		|| !parse_position(&(new->axis), tokens[2], 1.0) \
		|| !parse_color(&(new->color), tokens[5]))
	{
		free(new);
		return (NULL);
	}
	new->diameter = ft_strtof(tokens[3], NULL);
	new->height = ft_strtof(tokens[4], NULL);
	new->next = NULL;
	return (new);
}

bool	add_cylinder(t_scene *scene, char **tokens)
{
	t_object	*new;

	if (count_tokens(tokens) != TOKEN_COUNT_CY)
	{
		show_error(E_TOKEN_COUNT, objects_to_name(CYLINDER));
		return (FAILURE);
	}
	new = build_cylinder(tokens);
	if (new == NULL)
		return (FAILURE);
	append_object(scene, new);
	return (SUCCESS);
}
