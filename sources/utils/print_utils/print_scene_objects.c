/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene_objects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:02:44 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/05/07 11:28:38 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static void	util_print_plane(t_object *plane)
{
	printf("[%d][%s]\n", plane->index, objects_to_name(plane->type));
	printf("\tPos: \t");
	util_print_vector(plane->position);
	printf("\tDir: \t");
	util_print_vector(plane->orientation);
	print_color(plane->color);
	printf("\n");
}

static void	util_print_sphere(t_object *sphere)
{
	printf("[%d][%s]\n", sphere->index, objects_to_name(sphere->type));
	printf("\tPos: \t");
	util_print_vector(sphere->position);
	printf("\tDiam: \t%.1f\n", sphere->diameter);
	print_color(sphere->color);
	printf("\n");
}

static void	util_print_cylinder(t_object *cylinder)
{
	printf("[%d][%s]\n", cylinder->index, objects_to_name(cylinder->type));
	printf("\tPos: \t");
	util_print_vector(cylinder->position);
	printf("\tAxis: \t");
	util_print_vector(cylinder->axis);
	printf("\tDiam: \t%.1f\n", (cylinder->diameter));
	printf("\tHeig: \t%.1f\n", (cylinder->height));
	print_color(cylinder->color);
	printf("\n");
}

static void	util_print_cone(t_object *cone)
{
	printf("[%d][%s]\n", cone->index, objects_to_name(cone->type));
	printf("\tPos: \t");
	util_print_vector(cone->position);
	printf("\tAxis: \t");
	util_print_vector(cone->axis);
	printf("\tDiam: \t%.1f\n", (cone->diameter));
	printf("\tHeig: \t%.1f\n", (cone->height));
	print_color(cone->color);
	printf("\n");
}

void	print_objects(t_object *objects)
{
	t_object					*current;
	static const t_print_object	print_func[4] = {
		util_print_sphere,
		util_print_plane,
		util_print_cylinder,
		util_print_cone
	};

	current = objects;
	while (current != NULL)
	{
		print_func[(current->type - 3)](current);
		current = current->next;
	}
}
