/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:16:02 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/01/17 19:27:43 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_cylinder	*build_cylinder(char **tokens)
{
	t_cylinder		*cylinder;

	cylinder = safe_malloc(sizeof(t_cylinder), "build_cylinder()");
	cylinder->type = CYLINDER;
	cylinder->position = parse_position(tokens[1], 0.0);
	cylinder->axis = parse_position(tokens[2], 1.0);
	cylinder->diameter = ft_strtof(tokens[3], NULL); // ! Add checks to ft_strtof
	cylinder->height = ft_strtof(tokens[4], NULL);
	cylinder->color = parse_color(tokens[5]);
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
	if (count_tokens(tokens) != TOKEN_COUNT_CY)
		exit_with_message(E_TOKEN_COUNT, objects_to_name(CYLINDER), \
			X_FAILURE);

	append_cylinder(scene, build_cylinder(tokens));
	return (SUCCESS);
}
