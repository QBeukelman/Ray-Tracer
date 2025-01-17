/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:33:11 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/01/17 19:27:57 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_sphere		*build_sphere(char **tokens)
{
	t_sphere	*sphere;

	sphere = safe_malloc(sizeof(t_sphere), "build_sphere()");
	sphere->type = SPHERE;
	sphere->position = parse_position(tokens[1], 0.0);
	sphere->diameter = ft_strtof(tokens[2], NULL); // ! Add checks to ft_strtof
	sphere->color = parse_color(tokens[3]);
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
	if (count_tokens(tokens) != TOKEN_COUNT_SP)
		exit_with_message(E_TOKEN_COUNT, objects_to_name(SPHERE), \
			X_FAILURE);

	append_sphere(scene, build_sphere(tokens));
	return (SUCCESS);	
}
