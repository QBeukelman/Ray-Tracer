/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:11:34 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/01/19 17:12:29 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_plane	*free_plane(t_plane *plane)
{
	if (plane->position)
		free (plane->position);
	if (plane->orientation)
		free (plane->orientation);
	if (plane->color)
		free (plane->color);
	free (plane);
	return (NULL);
}

static t_plane	*build_plane(char **tokens)
{
	t_plane		*plane;
	t_vect		*position;
	t_vect		*orientation;
	t_color		*color;
	
	plane = malloc(sizeof(t_plane));
	if (plane == NULL)
	{
		show_error(E_MALLOC, "build_plane()");
		return (NULL);
	}
	plane->type = PLANE;
	position = parse_position(tokens[1], 0.0);
	orientation = parse_position(tokens[2], 1.0);
	color = parse_color(tokens[3]);
	if (!position || !orientation || !color)
		return (free_plane(plane));
	plane->position = position;
	plane->orientation = orientation;
	plane->color = color;
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
	t_plane		*new_plane;
	
	if (count_tokens(tokens) != TOKEN_COUNT_P)
	{
		show_error(E_TOKEN_COUNT, objects_to_name(PLANE));
		return (FAILURE);
	}
	new_plane = build_plane(tokens);
	if (new_plane == NULL)
		return (FAILURE);
	append_plane(scene, new_plane);
	return (SUCCESS);
}
