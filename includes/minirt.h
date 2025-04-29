/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:23 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/29 21:53:50 by quentinbeuk   ########   odam.nl         */
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
# include <stdint.h>
# include <string.h>

// ------------------------------------------------------------: colours
# define C_YELLOW "\033[1;33m"
# define C_RED "\x1B[1;31m"
# define RESET_COLOR "\033[0m"

// ------------------------------------------------------------: window
# define HEIGHT 500
# define WIDTH 800

typedef enum
{
	O_POSITION,
	O_ORIENTATION,
	O_DIAMETER,
	O_HEIGHT
} e_edit;

typedef enum
{
	V_X,
	V_Y,
	V_Z
} e_edit_vec;

typedef struct s_edit
{
	e_edit		editing_prop;
	e_edit_vec	editing_vec;
} t_edit;

// ------------------------------------------------------------: data
typedef struct s_mlx_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
} t_mlx_data;

// ------------------------------------------------------------: scene
typedef struct s_object
{
	int				index;
	e_object		type;
	bool			c_ray_relevant;
	t_vector		position;
	t_vector		axis;
	t_vector		orientation;
	double			diameter;
	double 			height;
	t_colour		colour;
	struct s_object	*next;
}	t_object;

typedef struct s_scene
{
	int					index_max;
	int					index_selected;
	struct s_edit		edit;
	t_ambi				ambi;
	t_camera			camera;
	t_light				light;
	struct s_object		*objects;
	t_vector			**rays;
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
	int		x;
	int		y;
	double	ndc_x;
	double	ndc_y;
	double	camera_x;
	double	camera_y;
} t_pixel;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}	t_rgb;

// TODO: Why not rgb?
typedef struct s_ambient
{
	double	r;
	double	g;
	double	b;
}	t_ambient;

typedef struct s_shading
{
	t_ray		ray;
	double		ray_length;
}	t_shading;

typedef struct s_matrix
{
	double x[3];
	double y[3];
	double z[3];
}	t_matrix;

// TODO: Why caps?
typedef struct s_FRU
{
	t_vector	forward;
	t_vector	right;
	t_vector	up;
}	t_FRU;

typedef struct s_all_data
{
	t_mlx_data	*mlx_data;
	t_scene		*scene;
} t_all_data;

typedef bool	(*t_add_func)(t_scene*, char **);

// ------------------------------------------------------------: controls
// adjust_value.c
void	increment_value(t_mlx_data *mlx_data, t_scene *scene);
void	decrement_value(t_mlx_data *mlx_data, t_scene *scene);

// select_object.c
t_object	*obj_for_index(t_object *objects, int index);
void		anounce_selection(t_scene *scene);
bool		increment_select(t_mlx_data *mlx_data, t_scene *scene);
bool		decrement_select(t_mlx_data *mlx_data, t_scene *scene);
char		*index_to_name(t_scene *scene, int index);

// select_property.c
bool	increment_property(t_mlx_data *mlx_data, t_scene *scene);

// select_vec.c
void	select_vec_x(t_mlx_data *mlx_data, t_scene *scene);
void	select_vec_y(t_mlx_data *mlx_data, t_scene *scene);
void	select_vec_z(t_mlx_data *mlx_data, t_scene *scene);


// ------------------------------------------------------------: mlx
// mlx_run.c
int		run_mlx(t_scene *scene);

// mlx_window_handler.c
int		ft_mlx_init(t_mlx_data *mlx_data);
void	ft_mlx_terminate(t_mlx_data mlx_data);


// ------------------------------------------------------------: mlx/input_hooks
// key_space.c
void	key_enter(t_mlx_data *mlx_data, t_scene *scene);

// key_hooks.c
void	ft_keyhook(mlx_key_data_t keydata, void *data);


// ------------------------------------------------------------: parse
// parse_scene.c
int		count_tokens(char **tokens);
bool	parser(t_scene *scene, const char *file_name);

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
void	free_rays(t_scene *scene);


// ------------------------------------------------------------: parse/parse_components
// build_colour.c
bool	parse_colour(t_colour *colour, char *token);

// build_int.c
bool	parse_int(int *fov, char *str);

// build_point_value.c
bool	parse_point_value(float *float_value, char *token);

// build_position.c
bool	parse_position(t_vector *vector, char *token, float limit);


// ------------------------------------------------------------: parse/parse_validations
// index_objects.c
void	index_objects(t_scene *scene);

// parser_post_validations.c
bool	validate_non_objects(t_scene *scene);

// parser_pre_validations.c
bool	is_valid_filename(const char *file_name);


// ------------------------------------------------------------: raytracer/collision
// plane.c
bool	plane_collision(t_object *plane, t_ray ray, t_collision *collision);

// sphere.c
bool	sphere_collision(t_object *sphere, t_ray ray, t_collision *collision);


// ------------------------------------------------------------: raytracer/shading
// shading.c
int	calculate_shading(t_collision *col, t_light *light, t_ambi *ambi, t_object *obj);


// ------------------------------------------------------------: raytracer/rendering
// background.c
// int	background(t_camera *c, double ray_y);

// render_image.c
bool 	is_collision(t_object *objects, t_ray ray, t_collision *collision);
bool 	collision_for_object(t_object *object, t_ray ray, t_collision *collision);
void	render_image(t_mlx_data *mlx, t_scene *scene);

// rays.c
void	generate_rays(t_vector **rays, t_camera *c);
bool	initialize_rays(t_scene *scene);

// world_martix.c
t_matrix	set_translation_matrix(int yaw, int pitch);
t_vector	set_ray_direction(t_vector ray, t_matrix m);


// ------------------------------------------------------------: utils
// colour_utils.c
int		rgba_to_int(int r, int g, int b, int a);
int		colour_to_int(t_colour *colour, int a);

// build_object_list.c
void	free_object_list(t_object *object);
void	append_object(t_scene *scene, t_object *new_object);

// radians_math.c
double	degrees_to_radians(double angle);
double	radians_to_degrees(double radians);


// ------------------------------------------------------------: utils/print_utils
// print_cylinder.c
void	print_cylinder(t_object *object, t_edit edit);

// print_lights_camera.c
void	print_camera(t_camera *camera, t_edit edit);
void	print_light(t_light *light, t_edit edit);
void	print_ambi(t_ambi *ambi);

// print_plane.c
void	print_plane(t_object *object, t_edit edit);

// print_sphere.c
void	print_sphere(t_object *sphere, t_edit edit);

// print_scene.c
void	print_scene(t_scene *scene);

// print_utils.c
void	print_label(const char *label, bool is_hilighted);
void	print_value(float value, bool is_hilighted);
void 	print_colour(t_colour colour);


#endif
