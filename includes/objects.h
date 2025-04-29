/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:18 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/29 21:50:50 by quentinbeuk   ########   odam.nl         */
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
typedef struct s_colour
{
	int		r;
	int		g;
	int		b;
} t_colour;


// ------------------------------------------------------------: objects
// TODO: Camera orientation as 3D normalized vector
typedef struct s_camera
{
	int			index;
	e_object	type;
	double		aspect_ratio;
	int			fov;
	double		fov_radians;
	t_vector	position;
	int			yaw;
	int			pitch;
	bool		initialized;
} t_camera;

typedef struct s_light
{
	int			index;
	e_object	type;
	t_vector	position;
	float		brightness;
	bool		initialized;
} t_light;

typedef struct s_ambi
{
	int				index;
	e_object		type;
	float			ratio;
	t_colour		colour;
	bool			initialized;

} t_ambi;

// ------------------------------------------------------------: parse
// scene_objects.c
char			*objects_to_string(e_object object);
char			*objects_to_name(e_object object);
e_object		string_to_objects(char *str);

#endif
