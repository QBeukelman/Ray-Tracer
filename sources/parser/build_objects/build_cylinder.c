/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:16:02 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/01/19 17:12:46 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_cylinder	*free_cylinder(t_cylinder *cylinder)
{
	if (cylinder->position)
		free (cylinder->position);
	if (cylinder->axis)
		free (cylinder->axis);
	if (cylinder->color)
		free (cylinder->color);
	free (cylinder);
	return (NULL);
}

static t_cylinder	*build_cylinder(char **tokens)
{
	t_cylinder		*cylinder;
	t_vect			*position;
	t_vect			*axis;
	t_color			*color;

	cylinder = malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
	{
		show_error(E_MALLOC, "build_cylinder()");
		return (NULL);
	}
	cylinder->type = CYLINDER;
	position = parse_position(tokens[1], 0.0);
	axis = parse_position(tokens[2], 1.0);
	color = parse_color(tokens[5]);
	if (!position || !axis || !color)
		return (free_cylinder(cylinder));
	cylinder->position = position;
	cylinder->axis = axis;
	cylinder->diameter = ft_strtof(tokens[3], NULL);
	cylinder->height = ft_strtof(tokens[4], NULL);
	cylinder->color = color;
	cylinder->next = NULL;
	return (cylinder);
}

static t_cylinder	*list_last(t_cylinder *cylinders)
{
	while (cylinders->next != NULL)
		cylinders = cylinders->next;
	return (cylinders);
}

static void	append_cylinder(t_scene *scene, t_cylinder *new_cylinder)
{
	t_cylinder		*root;

	root = scene->cylinders;
	if (scene->cylinders == NULL)
	{
		scene->cylinders = new_cylinder;
		return ;
	}
	else
		list_last(scene->cylinders)->next = new_cylinder;
	scene->cylinders = root;
}

bool	add_cylinder(t_scene *scene, char **tokens)
{
	t_cylinder		*new_cylinder;
	
	if (count_tokens(tokens) != TOKEN_COUNT_CY)
	{
		show_error(E_TOKEN_COUNT, objects_to_name(CYLINDER));
		return (FAILURE);
	}
	new_cylinder = build_cylinder(tokens);
	if (new_cylinder == NULL)
		return (FAILURE);
	append_cylinder(scene, new_cylinder);
	return (SUCCESS);
}
