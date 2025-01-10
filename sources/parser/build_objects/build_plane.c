/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:11:34 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/01/10 15:14:07 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_plane	*build_plane(char **tokens)
{
	t_plane		*plane;
	
	plane = safe_malloc(sizeof(t_plane), "build_plane()");
	plane->type = PLANE;
	plane->position = parse_position(tokens[1], 0.0);
	plane->orientation = parse_position(tokens[2], 1.0);
	plane->color = parse_color(tokens[3]);
	plane->next = NULL;
	return (plane);
}

static bool append_plane(t_scene *scene, t_plane *new_plane)
{
	t_plane		*current_plane;

	current_plane = NULL;
	if (scene->planes == NULL)
	{
		scene->planes = new_plane;
		return (SUCCESS);
	}
	else
	{
		current_plane = scene->planes;
		printf("curr: %p\n", current_plane);
		while (current_plane)
		{
			if (current_plane->next == NULL)
			{
				current_plane->next = new_plane;
				return (SUCCESS);
			}
			current_plane = current_plane->next;
		}
	}
	return (FAILURE);
}

bool	add_plane(t_scene *scene, char **tokens)
{
	if (count_tokens(tokens) != TOKEN_COUNT_P)
		exit_with_message(E_TOKEN_COUNT, objects_to_name(PLANE), \
			X_FAILURE);
	
	append_plane(scene, build_plane(tokens));
	return (SUCCESS);
}


