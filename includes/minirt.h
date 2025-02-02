/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:23 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/02/02 18:16:45 by hesmolde      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/includes/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "errors.h"
# include "objects.h"
# include "vector.h"
# include "camera.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdint.h>
# include <math.h>

// ------------------------------------------------------------: colors
# define C_YELLOW "\033[1;33m"
# define C_RED "\x1B[1;31m"
# define RESET_COLOR "\033[0m"

// ------------------------------------------------------------: window
# define HEIGHT 500
# define WIDTH 800

// ------------------------------------------------------------: data
typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
} t_data;

// ------------------------------------------------------------: scene
typedef struct s_scene
{
	struct s_ambi	*ambi;
	struct s_camera	*camera;
	struct s_light	*light;
	struct s_plane	*planes;
} t_scene;


// ------------------------------------------------------------: parse

// build_scene.c
t_scene		*build_scene(char *file_name);

// parser.c
int		ft_parse(char *file_name);

// splic_strings.c
char	**split_string(char *str);


// ------------------------------------------------------------: parse/build_objects
// add_objects.c
bool	add_object(t_scene *scene, char **tokens, e_object type);
int		count_tokens(char **tokens);

// build_ambient_light.c
bool	add_ambient_light(t_scene *scene, char **tokens);

// build_camera.c
bool	add_camera(t_scene *scene, char **tokens);

// build_light.c
bool 	add_light(t_scene *scene, char **tokens);

// build_plane.c
bool	add_plane(t_scene *scene, char **tokens);


// ------------------------------------------------------------: parse/parse_components
// build_color.c
t_color		*parse_color(char *token);

// build_int.c
int		parse_int(char *str, int limit);

// build_point_value.c
float	parse_point_value(char *token);

// build_position.c
t_vect	*parse_position(char *token, float limit);

// ------------------------------------------------------------: initialization
void	init_mlx(t_data *data);

// ------------------------------------------------------------: render_image
void	render_image(t_data *d, t_camera_data *c);

// ------------------------------------------------------------: background
int		get_rgba(int r, int g, int b, int a);
double	normalize_ray_y(t_camera_data *c, double ray_y);
int		background_colour(t_camera_data *c, double ray_y);


// ------------------------------------------------------------: utils
// function_protection.c
int		safe_open(char *file_name, int open_flags, ...);
void	*safe_malloc(size_t size, char *func_name);

// print_scene.c
void	print_scene(t_scene *scene);

#endif
