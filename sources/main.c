/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:42:04 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/02/07 23:41:38 by hesmolde      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *scene_file = "scenes/scene_00.rt";

	t_mlx_data	mlx;
	t_scene		scene;
	
	if (parse_scene(&scene, scene_file) == false)
		clear_list_exit_program(scene.objects);
	print_scene(&scene);
	// print_viewport(&scene);
	clear_list_exit_program(scene.objects);
	return (0);

	// init_mlx(&mlx);
	// render_image(&mlx, &scene);
	// mlx_image_to_window(mlx.mlx, mlx.img, 0, 0);
	// mlx_loop(mlx.mlx);
	// mlx_delete_image(mlx.mlx, mlx.img);
	// mlx_terminate(mlx.mlx);
}
