/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:42:04 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/01 19:51:53 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_mlx_data		mlx;
	t_scene			scene;
	const char		*file_name = "assets/scene_04.rt";

	(void)argc;
	(void)argv;
	if (parser(&scene, file_name) == false)
		return (FAILURE);
	
	// print_scene(&scene);

	if (initialize_rays(&scene) == false)
		free_object_list(scene.objects);
	run_mlx(&scene);
		free_object_list(scene.objects);
	free_rays(&scene);
	return (SUCCESS);
}
