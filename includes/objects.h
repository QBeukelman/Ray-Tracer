/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:18 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 20:31:16 by quentinbeuk   ########   odam.nl         */
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
# define TOKEN_COUNT_CN		6

# define INDEX_CAMERA 0
# define INDEX_LIGHT 1
# define INDEX_AMBI 2

# define CONST_2 2.0
# define CONST_MIN_2 -2.0
# define CONST_4 4

# define SPECULAR 0.9
# define SHININESS 20

# define OFFSET 0.0001

typedef enum e_object_type
{
	AMBIENT_LIGHT,
	LIGHT,
	CAMERA,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	NUM_OBJECTS
}	t_object_type;

// ------------------------------------------------------------: components
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;


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
}	t_viewport;

typedef struct s_camera
{
	t_object_type	type;
	double			aspect_ratio;
	int				fov;
	double			fov_radians;
	t_vector		position;
	int				yaw;
	int				pitch;
	t_vector		global_up;
	t_vector		orientation;
	t_vector		right;
	t_vector		up;
	t_viewport		viewport;
	bool			initialized;
}	t_camera;

typedef struct s_light
{
	t_object_type	type;
	t_vector		position;
	float			brightness;
	bool			initialized;
}	t_light;

typedef struct s_ambi
{
	t_object_type	type;
	float			ratio;
	t_color			color;
	bool			initialized;
}	t_ambi;

typedef struct s_cone
{
	t_vector	tip;
	t_vector	base;
	double		tipray_dot_axis;
	double		ray_dot_axis;
	double		tan_theta_sqr;
	double		origin_to_axis;
}	t_cone;

typedef struct s_cylinder
{
	t_vector	top_center;
	t_vector	bottom_center;
	t_vector	center_to_origin;
	t_vector	hit;
}	t_cylinder;

typedef struct s_object
{
	int				index;
	t_object_type	type;
	bool			c_ray_relevant;
	t_vector		position;
	t_vector		axis;
	t_vector		orientation;
	double			diameter;
	double			radius;
	double			height;
	t_color			color;
	struct s_object	*next;
}	t_object;


// ------------------------------------------------------------: parse
// scene_objects.c
char			*objects_to_string(t_object_type type);
char			*objects_to_name(t_object_type type);
t_object_type	string_to_objects(char *str);

#endif
