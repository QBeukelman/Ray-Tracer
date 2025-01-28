/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:42:04 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/01/28 22:14:08 by hesmolde      ########   odam.nl         */
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
	t_camera_data	camera;
	
	init_camera_data(&camera);
	// printf("viewport center x[%f] y[%f] z[%f]\n", camera.viewport.center.x, camera.viewport.center.y, camera.viewport.center.z);
	printf("bx[%f] by[%f] bz[%f]\n", camera.viewport.bottomleft.x, camera.viewport.bottomleft.y, camera.viewport.bottomleft.z);
	// printf("aspect ratio[%f]", camera.aspect_ratio);
	t_ray new = calculate_ray_direction(&camera, 0, 0);
	// printf("ray.x[%f] ray.y[%f] ray.y[%f]\n", new.direction.x, new.direction.y, new.direction.y);
	// new.direction = vec_normalize(new.direction);
	// printf("normalized ray.x[%f] ray.y[%f] ray.y[%f]\n", new.direction.x, new.direction.y, new.direction.y);
	exit(0);
	init_mlx(&data);
	mlx_loop(data.mlx);
	mlx_delete_image(data.mlx, data.img);
	mlx_terminate(data.mlx);
	exit(0);
}
