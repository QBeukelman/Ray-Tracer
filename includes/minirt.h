/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:23 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/02/23 11:12:20 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/includes/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "errors.h"
# include "vector.h"
# include "objects.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdint.h>
# include <math.h>

// ------------------------------------------------------------: colours
# define C_YELLOW "\033[1;33m"
# define C_RED "\x1B[1;31m"
# define RESET_COLOR "\033[0m"

// ------------------------------------------------------------: window
# define HEIGHT 500
# define WIDTH 800

// ------------------------------------------------------------: data
typedef struct s_mlx_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
} t_mlx_data;

// ------------------------------------------------------------: scene

typedef struct s_object
{
	e_object		type;
	bool			c_ray_relevant;
	t_vector		position;
	t_vector		axis;
	t_vector		orientation;
	double			diameter;
	double 			height;
	t_colour			colour;
	struct s_object	*next;
}	t_object;


typedef struct s_scene
{
	t_ambi		ambi;
	t_camera	camera;
	t_light		light;
	struct s_object		*objects;
} t_scene;

typedef struct s_collision
{
	t_object	*closest_obj;
	double		distance;
	t_vector	collision_point;
	t_vector	surface_normal;
} t_collision;

typedef struct s_pixel
{
	int	x;
	int	y;
} t_pixel;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}	t_rgb;

typedef bool	(*t_add_func)(t_scene*, char **);

// ------------------------------------------------------------: mlx
// init_window.c
void	init_mlx(t_mlx_data *data);

// ------------------------------------------------------------: parse
// parse_scene.c
int		count_tokens(char **tokens);
bool	parse_scene(t_scene *scene, const char *file_name);


// splic_strings.c
char	**split_string(char *str);


// ------------------------------------------------------------: parse/build_objects
// build_ambient_light.c
bool	add_ambient_light(t_scene *scene, char **tokens);

// build_camera.c
bool	add_camera(t_scene *scene, char **tokens);

// build_cylinder.c
bool	add_cylinder(t_scene *scene, char **tokens);

// build_light.c
bool 	add_light(t_scene *scene, char **tokens);

// build_plane.c
bool	add_plane(t_scene *scene, char **tokens);

// build_sphere.c
bool	add_sphere(t_scene *scene, char **tokens);


// ------------------------------------------------------------: parse/clean_up
// memory_cleanup.c
void	free_split(char **split);
void	free_scene(t_scene *scene);


// ------------------------------------------------------------: parse/parse_components
// build_colour.c
bool	parse_colour(t_colour *colour, char *token);

// build_int.c
bool	parse_int(int *fov, char *str);

// build_point_value.c
bool	parse_point_value(float *float_value, char *token);

// build_position.c
bool	parse_position(t_vector *vector, char *token, float limit);


// ------------------------------------------------------------: raytracer
// background.c
int		background(t_camera *c, double ray_y);

// pixel_loop.c
t_ray	calculate_ray(t_camera *c, int x, int y);
void	render_image(t_mlx_data *mlx, t_scene *scene);

// viewport.c
void	initialize_viewport(t_camera *camera);


// ------------------------------------------------------------: raytracer/collision
// sphere.c
bool	sphere_collision(t_object *sphere, t_ray ray, t_collision *collision);


// ------------------------------------------------------------: utils
// colour_utils.c
int		rgba_to_int(int r, int g, int b, int a);
int		colour_to_int(t_colour *colour, int a);

// function_protection.c
void	*safe_malloc(size_t size, char *func_name);

// print_scene.c
void	print_scene(t_scene *scene);
void	print_viewport(t_scene *scene);

// build_object_list.c
void	free_object_list(t_object *object);
void	clear_list_exit_program(t_object *object);
void	append_object(t_scene *scene, t_object *new_object);

#endif
