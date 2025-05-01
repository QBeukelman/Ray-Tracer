/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   select_vec.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 19:52:17 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/01 15:43:54 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	x_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	scene->edit.editing_vec = V_X;
	anounce_selection(scene);
}

void	y_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	scene->edit.editing_vec = V_Y;
	anounce_selection(scene);
}

void	z_key_hook(t_mlx_data *mlx_data, t_scene *scene)
{
	scene->edit.editing_vec = V_Z;
	anounce_selection(scene);
}
