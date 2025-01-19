/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:46:23 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/01/19 15:10:24 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

#include "libft/includes/libft.h"
#include "errors.h"
#include "objects.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdint.h>
#include <math.h>

// ------------------------------------------------------------: colors
# define C_YELLOW "\033[1;33m"
# define C_RED "\x1B[1;31m"
# define RESET_COLOR "\033[0m"


// ------------------------------------------------------------: scene
typedef struct s_scene
{
	struct s_ambi		*ambi;
	struct s_camera		*camera;
	struct s_light		*light;
	struct s_plane		*planes;
	struct s_sphere		*spheres;
	struct s_cylinder	*cylinders;
} t_scene;


// ------------------------------------------------------------: parse
// build_scene.c
int			count_tokens(char **tokens);
t_scene		*build_scene(char *file_name);

// parser.c
int		ft_parse(char *file_name);

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
// build_color.c
t_color		*parse_color(char *token);

// build_int.c
int		parse_int(char *str, int limit);

// build_point_value.c
float	parse_point_value(char *token);

// build_position.c
t_vect	*parse_position(char *token, float limit);


// ------------------------------------------------------------: utils
// function_protection.c
int		safe_open(char *file_name, int open_flags, ...);
void	*safe_malloc(size_t size, char *func_name);

// print_scene.c
void	print_scene(t_scene *scene);

#endif
