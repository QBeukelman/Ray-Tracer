/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_run.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 12:25:10 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/28 22:51:53 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	run_mlx(t_scene *scene)
{
	t_mlx_data		mlx_data;
	t_all_data		all_data;

	if (ft_mlx_init(&mlx_data) == FAILURE)
		return (FAILURE);

	render_image(&mlx_data, scene);
	mlx_image_to_window(mlx_data.mlx, mlx_data.img, 0, 0);
	
	anounce_selection(scene);
	
	all_data.mlx_data = &mlx_data;
	all_data.scene = scene;
	mlx_key_hook(mlx_data.mlx, &ft_keyhook, &all_data);
	mlx_loop(mlx_data.mlx);
	ft_mlx_terminate(mlx_data);
	return (SUCCESS);
}
