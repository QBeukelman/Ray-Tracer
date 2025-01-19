/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:46:18 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/01/19 11:59:07 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define TOKEN_COUNT_A		3
# define TOKEN_COUNT_L		3
# define TOKEN_COUNT_C		4
# define TOKEN_COUNT_SP		4
# define TOKEN_COUNT_P		4
# define TOKEN_COUNT_CY		6


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

typedef struct s_vect
{
	float	x;
	float	y;
	float	z;
} t_vect;


// ------------------------------------------------------------: objects
typedef struct s_ambi
{
	e_object		type;
	float			ambi_ratio;
	t_color			*color;
} t_ambi;

typedef struct s_camera
{
	e_object		type;
	struct s_vect	*position;
	struct s_vect	*orientation;
	unsigned int	fov;
} t_camera;

typedef struct s_light
{
	e_object		type;
	struct s_vect	*position;
	float			brightness;
} t_light;

typedef struct s_plane
{
	e_object		type;
	struct s_vect	*position;
	struct s_vect	*orientation;
	struct s_color	*color;
	struct s_plane	*next;
} t_plane;

typedef struct s_sphere
{
	e_object		type;
	struct s_vect	*position;
	double			diameter;
	struct s_color	*color;
	struct s_sphere	*next;
} t_sphere;

typedef struct s_cylinder
{
	e_object			type;
	struct s_vect		*position;
	struct s_vect		*axis;
	double				diameter;
	double 				height;
	struct s_color		*color;
	struct s_cylinder	*next;
} t_cylinder;


// ------------------------------------------------------------: parse
// scene_objects.c
char			*objects_to_string(e_object object);
char			*objects_to_name(e_object object);
e_object		string_to_objects(char *str);
