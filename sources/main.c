/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:42:04 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/05/02 14:41:31 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_mlx_data		mlx;
	t_scene			scene;
	const char		*file_name = "assets/scene_06.rt";

	(void)argc;
	(void)argv;
	if (parser(&scene, file_name) == false)
		return (FAILURE);
	
	print_scene(&scene);

	if (initialize_rays(&scene) == false)
		free_object_list(scene.objects);
	run_mlx(&scene);
		free_object_list(scene.objects);
	free_rays(&scene);
	return (SUCCESS);
}
