/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:42:04 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 20:12:00 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static bool	validate_args(int argc)
{
	if (argc != 2)
	{
		show_error(E_PROGRAM_IN, "");
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_scene			scene;

	if (validate_args(argc) == false)
		return (FAILURE);
	if (parser(&scene, argv[1]) == false)
		return (FAILURE);
	if (initialize_rays(&scene) == false)
		free_object_list(scene.objects);
	run_mlx(&scene);
	free_object_list(scene.objects);
	free_rays(&scene);
	return (SUCCESS);
}
