/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   select_object.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 13:12:30 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/29 21:57:11 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_object	*obj_for_index(t_object *objects, int index)
{
	t_object	*current;

	current = objects;
	while (current)
	{
		if (current->index == index)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	print_obj_for_index(t_scene *scene)
{
	t_object	*selected_object;

	if (scene->index_selected == 0)
		print_camera(selected_object, scene->edit);
	if (scene->index_selected == 1)
		print_light(selected_object, scene->edit);
	if (scene->index_selected == 2)
		print_ambi(selected_object);
	if (scene->index_selected > 2)
	{
		selected_object = obj_for_index(scene->objects, scene->index_selected);
		if (selected_object->type == SPHERE)
			print_sphere(selected_object, scene->edit);
		if (selected_object->type == PLANE)
			print_plane(selected_object, scene->edit);
		if (selected_object->type == CYLINDER)
			print_cylinder(selected_object, scene->edit);
	}
}

void	anounce_selection(t_scene *scene)
{
	printf("\033[2J\033[1;1H");
	printf("--------------------------------\n\n");
	print_obj_for_index(scene);
	printf("\n--------------------------------\n");
}

bool	increment_select(t_mlx_data *mlx_data, t_scene *scene)
{
	if (scene->index_selected == scene->index_max)
		scene->index_selected = 0;
	scene->index_selected++;
	anounce_selection(scene);
	return (true);
	
}

bool	decrement_select(t_mlx_data *mlx_data, t_scene *scene)
{
	if (scene->index_selected > 0)
		scene->index_selected--;
	else
		scene->index_selected = scene->index_max;
	anounce_selection(scene);
	return (true);
}
