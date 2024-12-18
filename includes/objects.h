/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:18 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/16 19:28:46 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# define TOKEN_COUNT_A		3
# define TOKEN_COUNT_L		
# define TOKEN_COUNT_C		
# define TOKEN_COUNT_SP		
# define TOKEN_COUNT_P		
# define TOKEN_COUNT_CY		

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



// ------------------------------------------------------------: parse
// scene_objects.c
char			*objects_to_string(e_object object);
char			*objects_to_name(e_object object);
e_object		string_to_objects(char *str);
