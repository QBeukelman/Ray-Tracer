/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/28 12:14:34 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/01/28 22:05:58 by hesmolde      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "minirt.h"
# include "vector.h"

typedef struct s_viewport
{
	double		D;
	t_vector	center;
	double		height;
	double		width;
	double		x_off;
	double		y_off;
	t_vector	bottomleft;
} t_viewport;

typedef struct s_camera_data
{
	double		aspect_ratio;
	int			FOV;
	t_vector	position;
	t_vector	global_up;
	t_vector	F;
	t_vector	R;
	t_vector	U;
	t_viewport	viewport;
} t_camera_data;

void	init_camera_data(t_camera_data *camera);
t_ray	calculate_ray_direction(t_camera_data *c, int x, int y);

#endif

