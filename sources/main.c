/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:42:04 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/02/22 12:51:39 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_mlx_data		mlx;
	t_scene			scene;
	const char		*scene_file = "assets/scene_01.rt";

	(void)argc;
	(void)argv;
	if (parse_scene(&scene, scene_file) == false)
		clear_list_exit_program(scene.objects);
	
	// TODO:
	// print_scene(&scene);
	// print_viewport(&scene);
	
	init_mlx(&mlx);
	render_image(&mlx, &scene);
	mlx_image_to_window(mlx.mlx, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
	mlx_delete_image(mlx.mlx, mlx.img);
	mlx_terminate(mlx.mlx);
	clear_list_exit_program(scene.objects);
}
