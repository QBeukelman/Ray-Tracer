/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   select_object.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 13:12:30 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/03 14:13:29 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	anounce_selection(t_scene *scene)
{
	printf("\033[2J\033[1;1H");
	printf("--------------------------------\n\n");
	print_obj_for_index(scene);
	printf("\n--------------------------------\n");
}

bool	right_bracket_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	if (scene->index_selected == scene->index_max)
		scene->index_selected = 0;
	scene->edit.editing_prop = O_POSITION;
	scene->edit.editing_vec = V_X;
	scene->index_selected++;
	anounce_selection(scene);
	return (true);
	
}

bool	left_bracket_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	if (scene->index_selected > 0)
		scene->index_selected--;
	else
		scene->index_selected = scene->index_max;
	scene->edit.editing_prop = O_POSITION;
	scene->edit.editing_vec = V_X;
	anounce_selection(scene);
	return (true);
}
