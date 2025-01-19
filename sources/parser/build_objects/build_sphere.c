/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:33:11 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/01/19 17:12:38 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_sphere		*free_sphere(t_sphere *sphere)
{
	if (sphere->position)
		free (sphere->position);
	if (sphere->color)
		free (sphere->color);
	free (sphere);
	return (NULL);
}

static t_sphere		*build_sphere(char **tokens)
{
	t_sphere	*sphere;
	t_vect		*position;
	t_color		*color;

	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
	{
		show_error(E_MALLOC, "build_sphere()");
		return (NULL);
	} 
	sphere->type = SPHERE;
	position = parse_position(tokens[1], 0.0);
	color = parse_color(tokens[3]);
	if (!position || !color)
		return (free_sphere(sphere));
	sphere->position = position;
	sphere->diameter = ft_strtof(tokens[2], NULL);
	sphere->color = color;
	sphere->next = NULL;
	return (sphere);
}

static t_sphere		*list_last(t_sphere *spheres)
{
	while (spheres->next != NULL)
		spheres = spheres->next;
	return (spheres);
}

static void		append_sphere(t_scene *scene, t_sphere *new_sphere)
{
	t_sphere	*root;

	root = scene->spheres;
	if (scene->spheres == NULL)
	{
		scene->spheres = new_sphere;
		return ;
	}
	else
		list_last(scene->spheres)->next = new_sphere;
	scene->spheres = root;
}

bool	add_sphere(t_scene *scene, char **tokens)
{
	t_sphere	*new_sphere;
	
	if (count_tokens(tokens) != TOKEN_COUNT_SP)
	{
		show_error(E_TOKEN_COUNT, objects_to_name(SPHERE));
		return (FAILURE);
	}
	new_sphere = build_sphere(tokens);
	if (new_sphere == NULL)
		return (FAILURE);
	append_sphere(scene, new_sphere);
	return (SUCCESS);
}
