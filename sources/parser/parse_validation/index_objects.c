/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index_objects.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 08:27:10 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/28 19:42:24 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

/*
 * 0 - 2 index for camera, light, ambi
*/
void index_objects(t_scene *scene)
{
	int			index;
	t_object	*current;

	index = 3;
	current = scene->objects;
	if (current == NULL)
		return ;
	while (current != NULL)
	{
		current->index = index;
		index++;
		current = current->next;
	}
	scene->index_selected = 0;
	scene->index_max = index - 1;
	scene->edit.editing_prop = O_POSITION;
	scene->edit.editing_vec = V_X;
}
