/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:23 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/07/19 22:01:39 by quentinbeuk   ########   odam.nl         */
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
# include <float.h>
# include <stdint.h>
# include <string.h>
# include <limits.h>
# include <errno.h>

// -----------------------------------------: colors
# define RESET_COLOR	"\033[0m"
# define C_BOLD		"\033[1m"
# define C_RED		"\033[1;31m"
# define C_GREEN	"\033[1;32m"
# define C_YELLOW	"\033[1;33m"
# define C_BLUE		"\033[1;34m"
# define C_MAGENTA	"\033[1;35m"
# define C_CYAN		"\033[1;36m"
# define C_WHITE	"\033[1;37m"

// -----------------------------------------: window
# define HEIGHT 600
# define WIDTH 1200

typedef enum e_edit_prop
{
	O_POSITION,
	O_ORIENTATION,
	O_CAMERA_PITCH,
	O_CAMERA_YAW,
	O_CAMERA_FOV,
	O_LIGHT_AMBI_RATIO,
	O_DIAMETER,
	O_HEIGHT
}	t_edit_prop;

typedef enum e_edit_vec
{
	V_X,
	V_Y,
	V_Z,
	V_NONE
}	t_edit_vec;

typedef struct s_edit
{
	t_edit_prop		editing_prop;
	t_edit_vec		editing_vec;
}	t_edit;

// -----------------------------------------: data
typedef struct s_mlx_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
}	t_mlx_data;

// -----------------------------------------: scene
typedef struct s_scene
{
	bool				is_rendering;
	int					index_max;
	int					index_selected;
	struct s_edit		edit;
	t_ambi				ambi;
	t_camera			camera;
	t_light				light;
	struct s_object		*objects;
	t_vector			**rays;
}	t_scene;

typedef struct s_collision
{
	t_object	*closest_obj;
	double		distance;
	t_vector	collision_point;
	t_vector	surface_normal;
}	t_collision;

typedef struct s_quadratic
{
	double	a;
	double	b;
	double	c;
}	t_quadratic;

typedef struct s_pixel
{
	int		x;
	int		y;
	double	ndc_x;
	double	ndc_y;
	double	camera_x;
	double	camera_y;
}	t_pixel;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}	t_rgb;

typedef struct s_shading
{
	t_ray		ray;
	double		ray_length;
	double		ambi_intensity;
	double		light_energy;
}	t_shading;

typedef struct s_matrix
{
	double	x[3];
	double	y[3];
	double	z[3];
}	t_matrix;

typedef struct s_fru
{
	t_vector	forward;
	t_vector	right;
	t_vector	up;
}	t_fru;

typedef struct s_all_data
{
	t_mlx_data	*mlx_data;
	t_scene		*scene;
}	t_all_data;

typedef bool	(*t_add_func)(t_scene*, char **);

// -----------------------------------------: controls
// adjust_value_camera.c
void		adjust_value_camera(t_scene *scene, int delta);

// adjust_value_lights.c
void		adjust_value_point_light(t_scene *scene, int delta);
void		adjust_value_ambi_light(t_scene *scene, double delta);

// adjust_value.c
typedef struct s_adjust_entry
{
	t_object_type	object_type;
	t_edit_prop		property_type;
	void			(*func)(t_object *obj, t_edit edit, double delta);
}	t_adjust_entry;

void		adjust_value_object(t_scene *scene, double delta);

// adjust_values.c
void		adjust_position(t_object *object, t_edit edit, double delta);
void		adjust_orientation(t_object *object, t_edit edit, double delta);
void		adjust_radius(t_object *object, t_edit edit, double delta);
void		adjust_height(t_object *object, t_edit edit, double delta);

// select_object.c
void		anounce_selection_and_instructions(t_scene *scene);
void		anounce_selection(t_scene *scene);
bool		right_bracket_key_hook(t_mlx_data *mlx_data, t_scene *scene);
bool		left_bracket_key_hook(t_mlx_data *mlx_data, t_scene *scene);

// select_property.c
void		tab_key_hook(t_mlx_data *mlx_data, t_scene *scene);

// select_vec.c
void		x_key_hook(t_mlx_data *mlx_data, t_scene *scene);
void		y_key_hook(t_mlx_data *mlx_data, t_scene *scene);
void		z_key_hook(t_mlx_data *mlx_data, t_scene *scene);

// -----------------------------------------: mlx
// mlx_run.c
int			run_mlx(t_scene *scene);

// mlx_window_handler.c
int			ft_mlx_init(t_mlx_data *mlx_data);
void		ft_mlx_terminate(t_mlx_data mlx_data);

// -----------------------------------------: mlx/input_hooks
// key_enter.c
void		enter_key_hook(t_mlx_data *mlx_data, t_scene *scene);

// key_hooks.c
void		ft_keyhook(mlx_key_data_t keydata, void *data);

// key_up_down.c
void		up_key_hook(t_mlx_data *mlx_data, t_scene *scene);
void		down_key_hook(t_mlx_data *mlx_data, t_scene *scene);

// -----------------------------------------: parse
// parse_scene.c
int			count_tokens(char **tokens);
bool		parser(t_scene *scene, const char *file_name);

// splic_strings.c
char		**split_string(char *str);

// -----------------------------------------: parse/build_objects
// build_ambient_light.c
bool		add_ambient_light(t_scene *scene, char **tokens);

// build_camera.c
bool		add_camera(t_scene *scene, char **tokens);

// build_cone.c
bool		add_cone(t_scene *scene, char **tokens);

// build_cylinder.c
bool		add_cylinder(t_scene *scene, char **tokens);

// build_light.c
bool		add_light(t_scene *scene, char **tokens);

// build_plane.c
bool		add_plane(t_scene *scene, char **tokens);

// build_sphere.c
bool		add_sphere(t_scene *scene, char **tokens);

// -----------------------------------------: parse/parse_components
// build_color.c
bool		parse_color(t_color *color, char *token);

// build_int.c
bool		parse_int(int *fov, char *str);

// build_point_value.c
bool		parse_point_value(float *float_value, char *token);

// build_position.c
bool		parse_position(t_vector *vector, char *token, float limit);

// -----------------------------------------: parse/parse_validations
// index_objects.c
void		index_objects(t_scene *scene);

// parser_post_validations.c
bool		validate_non_objects(t_scene *scene);

// parser_pre_validations.c
bool		is_valid_filename(const char *file_name);

// -----------------------------------------: raytracer/collision
// cone_distance.c
bool		solve_for_t_cone(double *t, t_cone *c, t_object *cone, t_ray ray);

// cone.c
bool		cone_collision(t_object *cylinder, t_ray ray, t_collision *col);

// cylinder.c
bool		cylinder_collision(t_object *cylinder, t_ray ray, t_collision *col);

// plane.c
double		hit_flat_plane(double *t, t_ray ray, t_vector p, \
	t_vector orientation);
bool		plane_collision(t_object *plane, t_ray ray, t_collision *collision);

// sphere.c
bool		sphere_collision(t_object *sphere, t_ray ray, \
	t_collision *collision);
double		collision_dst(double a, double b, double discriminant);

// -----------------------------------------: raytracer/rendering
// render_image.c
typedef bool	(*t_collision_func)(t_object *, t_ray, t_collision *);
bool		is_collision(t_object *objects, t_ray ray, t_collision *collision);
void		render_image(t_mlx_data *mlx, t_scene *scene);

// rays.c
bool		initialize_rays(t_scene *scene);

// world_martix.c
t_matrix	set_rotation_matrix(int yaw, int pitch);
t_vector	set_ray_direction(t_vector ray, t_matrix m);

// -----------------------------------------: raytracer/shading
// shading.c
int			calculate_shading(t_collision *col, t_scene *scene, t_ray ray);

//light.c
t_rgb		ambient_light(t_ambi ambi);
t_rgb		diffuse_light(t_collision *col, float bright, t_shading r, \
	t_rgb ambi);
double		specular_light(t_collision *col, t_ray ray, t_shading r);

// -----------------------------------------: utils
// color_utils.c
int			rgba_to_int(int r, int g, int b, int a);
int			color_to_int(t_color *color, int a);

// build_object_list.c
void		free_object_list(t_object *object);
void		append_object(t_scene *scene, t_object *new_object);

// radians_math.c
double		degrees_to_radians(double angle);
double		radians_to_degrees(double radians);

// utils.c
double		in_range(double value, double min, double max);
bool		free_split(char **split);
void		free_rays(t_scene *scene);

// -----------------------------------------: utils/print_utils
// print_cone.c
void		print_cone(t_object *object, t_edit edit);

// print_cylinder.c
void		print_cylinder(t_object *object, t_edit edit);

// print_lights_camera.c
void		print_camera(t_camera camera, t_edit edit);
void		print_light(t_light light, t_edit edit);
void		print_ambi(t_ambi ambi);

// print_objects.c
t_object	*obj_for_index(t_object *objects, int index);
void		print_obj_for_index(t_scene *scene);

// print_plane.c
void		print_plane(t_object *object, t_edit edit);

// print_scene_objects.c
typedef void	(*t_print_object)(t_object*);
void		print_objects(t_object *objects);

// print_scene.c
void		util_print_vector(t_vector vec);
void		print_scene(t_scene *scene);

// print_sphere.c
void		print_sphere(t_object *sphere, t_edit edit);

// print_utils.c
void		print_label(const char *label, bool is_hilighted);
void		print_value(float value, bool is_hilighted, t_edit_vec vec);
void		print_color(t_color color);

#endif
