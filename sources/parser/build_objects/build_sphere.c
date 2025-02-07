/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/17 18:33:11 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/02/07 03:02:51 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_object		*build_sphere(char **tokens)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (new == NULL)
	{
		show_error(E_MALLOC, "build_sphere()");
		return (NULL);
	}
	ft_memset(new, 0, sizeof(t_object));
	new->type = SPHERE;
	if (!parse_position(new->position, tokens[1], 0.0) \
		|| !parse_color(new, tokens[3]))
	{
		return (NULL);
	}
	new->diameter = ft_strtof(tokens[2], NULL);
	new->next = NULL;
	return (new);
}

bool	add_sphere(t_scene *scene, char **tokens)
{	
	t_object	*new;
	
	if (count_tokens(tokens) != TOKEN_COUNT_SP)
	{
		show_error(E_TOKEN_COUNT, objects_to_name(SPHERE));
		return (FAILURE);
	}
	new = build_sphere(tokens);
	if (new == NULL)
		return (FAILURE);
	append_object(scene, new);
	return (SUCCESS);
}
