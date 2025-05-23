/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   select_object.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 13:12:30 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 21:48:39 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	anounce_selection_and_instructions(t_scene *scene)
{
	printf("\033[2J\033[1;1H");
	printf("--------------------------------\n");
	printf(C_YELLOW);
	printf("Select object:\n");
	printf("\t`[` Previous object.\n");
	printf("\t`]` Next object.\n");
	printf("\nSelect edit property:\n");
	printf("\t`tab` Select next edit property.\n");
	printf("\nSelect vecor:\n");
	printf("\t`x` Select x vector.\n");
	printf("\t`y` Select y vector.\n");
	printf("\t`z` Select z vector.\n");
	printf("\nAdjust property value:\n");
	printf("\t`↑` Increment value.\n");
	printf("\t`↓` Increment value.\n");
	printf(RESET_COLOR);
	printf("--------------------------------\n\n");
	print_obj_for_index(scene);
	printf("\n--------------------------------\n");
}

void	anounce_selection(t_scene *scene)
{
	printf("\033[2J\033[1;1H");
	printf("--------------------------------\n");
	printf(C_YELLOW);
	printf("Press [i] for instructions\n");
	printf(RESET_COLOR);
	printf("--------------------------------\n\n");
	print_obj_for_index(scene);
	printf("\n--------------------------------\n");
}

bool	right_bracket_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	(void)mlx_data;
	if (scene->index_selected == scene->index_max)
		scene->index_selected = 0;
	scene->index_selected++;
	scene->edit.editing_prop = O_POSITION;
	if (scene->index_selected == 2)
		scene->edit.editing_prop = O_LIGHT_AMBI_RATIO;
	scene->edit.editing_vec = V_X;
	anounce_selection(scene);
	return (true);
}

bool	left_bracket_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	(void)mlx_data;
	if (scene->index_selected > 0)
		scene->index_selected--;
	else
		scene->index_selected = scene->index_max;
	scene->edit.editing_prop = O_POSITION;
	if (scene->index_selected == 2)
		scene->edit.editing_prop = O_LIGHT_AMBI_RATIO;
	scene->edit.editing_vec = V_X;
	anounce_selection(scene);
	return (true);
}
