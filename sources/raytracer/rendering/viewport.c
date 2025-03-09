/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   viewport.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 23:28:14 by hein          #+#    #+#                 */
/*   Updated: 2025/03/09 00:32:05 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

#define RADIAN_CONST 0.0174533

// void	initialize_viewport(t_camera *camera)
// {
// 	camera->aspect_ratio = (double)WIDTH / (double)HEIGHT;
// 	if (fabs(camera->orientation.y) < 0.99)
// 	{
// 		printf("1\n");
// 		camera->global_up = vec_set(0, 1, 0);
// 	}
// 	else
// 	{
// 		printf("2\n");
// 		camera->global_up = vec_set(0, 0, 1);
// 	}
// 	camera->right = vec_normalize(vec_cross(camera->orientation, camera->global_up));
// 	// camera->right = vec_normalize(camera->right);
// 	// if (camera->right.x < 0)
// 	// 	camera->right = vec_scale(camera->right, -1);
// 	// camera->right = vec_abs(camera->right);
// 	camera->up = vec_cross(camera->right, camera->orientation);
// 	// if (camera->up.y < 0)
// 	// 	camera->up = vec_scale(camera->up, -1);
// 	// camera->up = vec_abs(camera->up);
// 	// printf("camera->forward			x[%f] y[%f] z[%f]\n", camera->orientation.x, camera->orientation.y, camera->orientation.z);
// 	// printf("camera->right			x[%f] y[%f] z[%f]\n", camera->right.x, camera->right.y, camera->right.z);
// 	// printf("camera->up			x[%f] y[%f] z[%f]\n", camera->up.x, camera->up.y, camera->up.z);
// 	// printf("dot product between up and forward [%f]\n", vec_dot(camera->orientation, camera->up));
// 	// printf("dot product between up and right [%f]\n", vec_dot(camera->right, camera->up));
// 	// printf("dot product between right and forward [%f]\n", vec_dot(camera->orientation, camera->right));
// 	// exit(1);
// 	// calculate_viewport(camera);
// }

