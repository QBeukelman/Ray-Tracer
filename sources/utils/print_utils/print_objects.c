/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_objects.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/03 12:15:55 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/03 12:23:51 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/*
 * Returns the object for a given index from a linked list of objects.
 *
 * Parameters:
 *   objects - pointer to the head of a linked list of t_object
 *   index   - the target index to search for in the list
 *
 * Return:
 *   A pointer to the t_object with the matching index if found.
 *   Returns NULL if:
 *     - the index is less than 2 (invalid),
 *     - or if no object with the given index exists in the list.
 *
 * Note:
 *   Assumes each t_object in the list has a unique 'index' field and a 'next' pointer.
 */
t_object	*obj_for_index(t_object *objects, int index)
{
	t_object	*current;

	if (index < 2)
		return (NULL);
		
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
		print_camera(scene->camera, scene->edit);
	if (scene->index_selected == 1)
		print_light(scene->light, scene->edit);
	if (scene->index_selected == 2)
		print_ambi(scene->ambi);
	if (scene->index_selected > 2)
	{
		selected_object = obj_for_index(scene->objects, scene->index_selected);
		if (selected_object->type == SPHERE)
			print_sphere(selected_object, scene->edit);
		if (selected_object->type == PLANE)
			print_plane(selected_object, scene->edit);
		if (selected_object->type == CYLINDER)
			print_cylinder(selected_object, scene->edit);
		if (selected_object->type == CONE)
			print_cone(selected_object, scene->edit);
	}
}
