/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:23 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/16 19:31:14 by quentinbeuk   ########   odam.nl         */
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

// ------------------------------------------------------------: colors
# define C_YELLOW "\033[1;33m"
# define C_RED "\x1B[1;31m"
# define RESET_COLOR "\033[0m"


// ------------------------------------------------------------: scene
typedef struct s_scene
{
	struct s_ambi	*ambi;
} t_scene;


// ------------------------------------------------------------: parse
// build_color.c
t_color		*parse_color(char *token);

// build_scene.c
int		build_scene(char *file_name);

// parser.c
int		ft_parse(char *file_name);

// splic_strings.c
char	**split_string(char *str);


// ------------------------------------------------------------: parse/validate
// build_objects.c
bool	add_object(t_scene *scene, char **tokens, e_object type);
int		count_tokens(char **tokens);

// build_ambient_light.c
bool	add_ambient_light(t_scene *scene, char **tokens);



// ------------------------------------------------------------: utils
// function_protection.c
int		safe_open(char *file_name, int open_flags, ...);
void	*safe_malloc(size_t size, char *func_name);

#endif
