/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:42:04 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/02/05 00:08:21 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int main(int argc, char **argv)
{
	
	(void)argc;
	(void)argv;
	ft_parse("scenes/scene_00.rt");
	return (0);
}

// int main(int argc, char **argv)
// {

// 	(void)argc;
// 	(void)argv;
// 	t_data			data;
// 	t_camera_data	camera;
	
// 	ft_memset(&data, 0, sizeof(data));
// 	init_mlx(&data);
// 	init_camera_data(&camera);
// 	// printf("viewport center x[%f] y[%f] z[%f]\n", camera.viewport.center.x, camera.viewport.center.y, camera.viewport.center.z);
// 	// printf("bx[%f] by[%f] bz[%f]\n", camera.viewport.bottomleft.x, camera.viewport.bottomleft.y, camera.viewport.bottomleft.z);
// 	// printf("aspect ratio[%f]", camera.aspect_ratio);
// 	// t_ray new = calculate_ray_direction(&camera, 0, 0);
// 	// printf("output for pixel 0,0\n");
// 	// printf("ray.x[%f] ray.y[%f] ray.z[%f]\n", new.direction.x, new.direction.y, new.direction.z);
// 	// new = calculate_ray_direction(&camera, 799, 0);
// 	// printf("output for pixel 799,0\n");
// 	// printf("ray.x[%f] ray.y[%f] ray.z[%f]\n", new.direction.x, new.direction.y, new.direction.z);
// 	// new = calculate_ray_direction(&camera, 799, 499);
// 	// printf("output for pixel 799,499\n");
// 	// printf("ray.x[%f] ray.y[%f] ray.z[%f]\n", new.direction.x, new.direction.y, new.direction.z);
// 	// new = calculate_ray_direction(&camera, 0, 499);
// 	// printf("output for pixel 0,499\n");
// 	// printf("ray.x[%f] ray.y[%f] ray.z[%f]\n", new.direction.x, new.direction.y, new.direction.z);
// 	// exit(0);
// 	// new.direction = vec_normalize(new.direction);
// 	// printf("normalized ray.x[%f] ray.y[%f] ray.y[%f]\n", new.direction.x, new.direction.y, new.direction.y);
// 	// exit(0);
// 	render_image(&data, &camera);
// 	if (data.mlx == NULL)
// 	{
// 		printf("MLX = NULL");
// 		exit(1);
// 	}
// 	if (data.img == NULL)
// 	{
// 		printf("IMG = NULL");
// 		exit(1);
// 	}
// 	// mlx_put_pixel(data.img, 399, 249, get_rgba(100, 100, 100, 255));
// 	mlx_image_to_window(data.mlx, data.img, 0, 0);
// 	mlx_loop(data.mlx);
// 	mlx_delete_image(data.mlx, data.img);
// 	mlx_terminate(data.mlx);
// 	exit(0);
// }

// void	init_mlx(t_data *data)
// {
// 	data->mlx = mlx_init(WIDTH, HEIGHT, "MINI_RT", false);
// 	if (!data->mlx)
// 		exit(1);
// 	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
// 	if (!data->img)
// 	{
// 		mlx_terminate(data->mlx);
// 		exit(1);
// 	}
// }

// int main(int argc, char **argv)
// {
// 	t_data			data;
// 	t_camera_data	camera;
	
// 	init_mlx(&data);
// 	init_camera_data(&camera);
// 	render_image(&data, &camera);
// 	// mlx_image_to_window(data.mlx, data.img, 0, 0);
// 	mlx_loop(data.mlx);
// 	mlx_delete_image(data.mlx, data.img);
// 	mlx_terminate(data.mlx);
// 	exit(0);
// }
