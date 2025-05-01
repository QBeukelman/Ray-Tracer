/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_plane.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 13:11:34 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/04/30 13:35:32 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_object	*build_plane(char **tokens)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (new == NULL)
	{
		show_error(E_MALLOC, "build_plane()");
		return (NULL);
	}
	ft_memset(new, 0, sizeof(t_object));
	new->type = PLANE;
	if (!parse_position(&(new->position), tokens[1], 0.0) \
		|| !parse_position(&(new->orientation), tokens[2], 1.0) \
		|| !parse_colour(&(new->colour), tokens[3]))
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

bool	add_plane(t_scene *scene, char **tokens)
{
	t_object	*new;

	if (count_tokens(tokens) != TOKEN_COUNT_P)
	{
		show_error(E_TOKEN_COUNT, objects_to_name(PLANE));
		return (FAILURE);
	}
	new = build_plane(tokens);
	if (new == NULL)
		return (FAILURE);
	new->orientation = vec_normalize(new->orientation);
	append_object(scene, new);
	return (SUCCESS);
}
