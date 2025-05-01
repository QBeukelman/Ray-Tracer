/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:18 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/01 19:30:44 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vector.h"
# include <stdbool.h>

# define TOKEN_COUNT_A		3
# define TOKEN_COUNT_L		3
# define TOKEN_COUNT_C		4
# define TOKEN_COUNT_SP		4
# define TOKEN_COUNT_P		4
# define TOKEN_COUNT_CY		6

# define INDEX_CAMERA 0
# define INDEX_LIGHT 1
# define INDEX_AMBI 2

typedef enum {
	AMBIENT_LIGHT,
	LIGHT,
	CAMERA,
	SPHERE,
	PLANE,
	CYLINDER,
	NUM_OBJECTS
} e_object;

// ------------------------------------------------------------: components
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
} t_color;


// ------------------------------------------------------------: objects
typedef struct s_viewport
{
	double		distance;
	t_vector	center;
	double		height;
	double		width;
	double		x_off;
	double		y_off;
	t_vector	bottomleft;
} t_viewport;

// TODO: Camera orientation as 3D normalized vector
typedef struct s_camera
{
	e_object	type;
	double		aspect_ratio;
	int			fov;
	double		fov_radians;
	t_vector	position;
	int			yaw;
	int			pitch;
	t_vector	global_up;
	t_vector	orientation;
	t_vector	right;
	t_vector	up;
	t_viewport	viewport;
	bool		initialized;
} t_camera;

typedef struct s_light
{
	e_object	type;
	t_vector	position;
	float		brightness;
	bool		initialized;
} t_light;

typedef struct s_ambi
{
	e_object		type;
	float			ratio;
	t_color			color;
	bool			initialized;
} t_ambi;

typedef struct s_cap
{
	double 		distance;
	double 		denominator;
	t_vector	intersection;
}	t_cap;

typedef struct s_cylinder
{
	t_vector	top_center;
	t_vector	bottom_center;
	t_vector	ray_to_axis_cross;
	t_vector	center_to_origin;
	t_vector	orientation_cross;
	t_vector	hit_point;
	t_vector	body_from_center;
	double		axis_distance;
} t_cylinder;

typedef struct s_object
{
	int				index;
	e_object		type;
	bool			c_ray_relevant;
	t_vector		position;
	t_vector		axis;
	t_vector		orientation;
	double			diameter;
	double			radius;
	double 			height;
	t_color			color;
	struct s_object	*next;
}	t_object;


// ------------------------------------------------------------: parse
// scene_objects.c
char			*objects_to_string(e_object object);
char			*objects_to_name(e_object object);
e_object		string_to_objects(char *str);

#endif
