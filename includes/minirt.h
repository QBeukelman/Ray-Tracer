/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:23 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/26 00:24:26 by quentinbeuk   ########   odam.nl         */
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

// ------------------------------------------------------------: colors
# define C_YELLOW "\033[1;33m"
# define C_RED "\x1B[1;31m"
# define RESET_COLOR "\033[0m"


// ------------------------------------------------------------: scene
typedef struct s_scene
{
	struct s_ambi	*ambi;
	struct s_camera	*camera;
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


// ------------------------------------------------------------: parse/parse_components
// build_color.c
t_color		*parse_color(char *token);

// build_point_value.c
float	parse_point_value(char *token);

// build_position.c
t_vect	*parse_position(char *token);



// ------------------------------------------------------------: utils
// function_protection.c
int		safe_open(char *file_name, int open_flags, ...);
void	*safe_malloc(size_t size, char *func_name);

// print_scene.c
void	print_scene(t_scene *scene);

#endif
