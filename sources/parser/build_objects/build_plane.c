/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:11:34 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/01/17 18:55:01 by qbeukelm         ###   ########.fr       */
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

static t_plane		*list_last(t_plane *planes)
{
	while (planes->next != NULL)
		planes = planes->next;
	return (planes);
}

static void append_plane(t_scene *scene, t_plane *new_plane)
{
	t_plane		*root;
	
	root = scene->planes;
	if (scene->planes == NULL)
	{
		scene->planes = new_plane;
		return ;
	}
	else
		list_last(scene->planes)->next = new_plane;
	scene->planes = root;
}

bool	add_plane(t_scene *scene, char **tokens)
{
	if (count_tokens(tokens) != TOKEN_COUNT_P)
		exit_with_message(E_TOKEN_COUNT, objects_to_name(PLANE), \
			X_FAILURE);
	
	append_plane(scene, build_plane(tokens));
	return (SUCCESS);
}
