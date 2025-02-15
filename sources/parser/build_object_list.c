/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_object_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:01:58 by hesmolde          #+#    #+#             */
/*   Updated: 2025/02/15 13:08:12 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	free_object_list(t_object *object)
{
	t_object	*temp;

	while (object != NULL)
	{
		temp = object->next;
		free(object);
		object = temp;
	}
}

void	clear_list_exit_program(t_object *object)
{
	free_object_list(object);
	exit(1);
}

static	t_object	*list_last(t_object *object)
{
	while (object->next != NULL)
		object = object->next;
	return (object);
}

void	append_object(t_scene *scene, t_object *new_object)
{
	t_object	*root;

	root = scene->objects;
	if (scene->objects == NULL)
	{
		scene->objects = new_object;
		return ;
	}
	list_last(scene->objects)->next = new_object;
	scene->objects = root;
}
