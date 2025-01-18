/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:42:04 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/01/17 16:58:32 by hesmolde      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

// int main(int argc, char **argv)
// {
// 	ft_parse("scenes/scene_00.rt");
// 	return (0);
// }

int main(int argc, char **argv)
{
	t_data	data;

	init_mlx(&data);
	mlx_loop(data.mlx);
	mlx_delete_image(data.mlx, data.img);
	mlx_terminate(data.mlx);
	exit(0);
}
