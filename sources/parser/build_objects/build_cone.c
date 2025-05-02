/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:31:30 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/05/02 14:38:47 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_object	*build_cone(char **tokens)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (new == NULL)
	{
		show_error(E_MALLOC, "build_cone()");
		return (NULL);
	}
	ft_memset(new, 0, sizeof(t_object));
	new->type = CONE;
	if (!parse_position(&(new->position), tokens[1], 0.0) \
		|| !parse_position(&(new->orientation), tokens[2], 1.0) \
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

bool add_cone(t_scene *scene, char **tokens)
{
	t_object	*new;
	
	if (count_tokens(tokens) != TOKEN_COUNT_CN)
	{
		show_error(E_TOKEN_COUNT, objects_to_name(CONE));
		return (FAILURE);
	}
	new = build_cone(tokens);
	if (new == NULL)
		return (FAILURE);
	new->orientation = vec_normalize(new->orientation);
	new->radius = new->diameter / 2;
	append_object(scene, new);
	return (SUCCESS);
}
