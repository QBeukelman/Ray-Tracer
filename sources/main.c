/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:42:04 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/08 16:01:12 by hein          ########   odam.nl         */
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
	scene.rays = allocate_rays();
	if (scene.rays == NULL)
		clear_list_exit_program(scene.objects);
	generate_rays(scene.rays, &(scene.camera));
	// initialize_viewport(&(scene.camera));
	printf("ray for pixel 0,0		x[%f] y[%f] z[%f]\n", scene.rays[0][0].x, scene.rays[0][0].y, scene.rays[0][0].z);
	printf("ray for pixel 0,499		x[%f] y[%f] z[%f]\n", scene.rays[499][0].x, scene.rays[499][0].y, scene.rays[499][0].z);
	printf("ray for pixel 0,799		x[%f] y[%f] z[%f]\n", scene.rays[0][799].x, scene.rays[0][799].y, scene.rays[0][799].z);
	printf("ray for pixel 499,799		x[%f] y[%f] z[%f]\n", scene.rays[499][799].x, scene.rays[499][799].y, scene.rays[499][799].z);
	// print_scene(&scene);
	// print_viewport(&scene);
	// run_mlx(scene);
	free(scene.rays[0]);
	free(scene.rays);
	clear_list_exit_program(scene.objects);
	return (SUCCESS);
}
