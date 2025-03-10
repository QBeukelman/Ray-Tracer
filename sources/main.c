/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:42:04 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/04 22:45:08 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	run_mlx(t_scene scene)
{
	t_mlx_data		mlx_data;
	t_all_data		all_data;

	if (ft_mlx_init(&mlx_data) == FAILURE)
		return (FAILURE);

	render_image(&mlx_data, &scene);
	mlx_image_to_window(mlx_data.mlx, mlx_data.img, 0, 0);

	all_data.mlx_data = &mlx_data;
	all_data.scene = &scene;
	mlx_key_hook(mlx_data.mlx, &ft_keyhook, &all_data);
	mlx_loop(mlx_data.mlx);
	ft_mlx_terminate(mlx_data);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_scene			scene;
	const char		*scene_file = "assets/scene_02.rt";

	(void)argc;
	(void)argv;
	if (parse_scene(&scene, scene_file) == false)
		clear_list_exit_program(scene.objects);
	
	// print_scene(&scene);
	// print_viewport(&scene);
	run_mlx(scene);
	clear_list_exit_program(scene.objects);
	return (SUCCESS);
}
