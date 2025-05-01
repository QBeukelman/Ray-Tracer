/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   world_matrix.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 23:28:14 by hein          #+#    #+#                 */
/*   Updated: 2025/05/01 11:44:44 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_vector	set_camera_forward(int yaw, int pitch)
{
	t_vector		forward;
	const double	yawRad = degrees_to_radians(yaw);
	const double	pitchRad = degrees_to_radians(pitch);

	forward.x = -sinf(yawRad) * cosf(pitchRad);
	forward.y = sinf(pitchRad);
	forward.z = cosf(yawRad) * cosf(pitchRad);
	return (vec_normalize(forward));
}

static t_fru	set_FRU_orientations(int yaw, int pitch)
{
	t_fru		camera;
	t_vector	worldUp;

	camera.forward = set_camera_forward(yaw, pitch);
	if (camera.forward.y > 0.98)
	{
		worldUp = vec_set(0, 0, 1);
	}
	else
	{
		worldUp = vec_set(0, 1, 0);
	}
	camera.right = vec_normalize(vec_cross(worldUp, camera.forward));
	camera.up = vec_normalize(vec_cross(camera.forward, camera.right));
	return (camera);

}

t_matrix	set_translation_matrix(int yaw, int pitch)
{
	t_matrix	matrix;
	const t_fru	camera = set_FRU_orientations(yaw, pitch);
	matrix.x[0] = camera.right.x;
	matrix.x[1] = camera.up.x;
	matrix.x[2] = camera.forward.x;
	matrix.y[0] = camera.right.y;
	matrix.y[1] = camera.up.y;
	matrix.y[2] = camera.forward.y;
	matrix.z[0] = camera.right.z;
	matrix.z[1] = camera.up.z;
	matrix.z[2] = camera.forward.z;
	return (matrix);
}

t_vector	set_ray_direction(t_vector ray, t_matrix m)
{
	t_vector	new;

	new.x = ray.x * m.x[0] + ray.y * m.x[1] + ray.z * m.x[2];
	new.y = ray.x * m.y[0] + ray.y * m.y[1] + ray.z * m.y[2];
	new.z = ray.x * m.z[0] + ray.y * m.z[1] + ray.z * m.z[2];
	return (vec_normalize(new));
}
