/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   select_vec.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 19:52:17 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/28 19:58:42 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	select_vec_x(t_mlx_data *mlx_data, t_scene *scene)
{
	scene->edit.editing_vec = V_X;
	anounce_selection(scene);
}

void	select_vec_y(t_mlx_data *mlx_data, t_scene *scene)
{
	scene->edit.editing_vec = V_Y;
	anounce_selection(scene);
}

void	select_vec_z(t_mlx_data *mlx_data, t_scene *scene)
{
	scene->edit.editing_vec = V_Z;
	anounce_selection(scene);
}
