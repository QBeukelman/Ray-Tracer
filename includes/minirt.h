/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:23 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/13 13:23:42 by quentinbeuk   ########   odam.nl         */
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


// ------------------------------------------------------------: parse
// parser.c
int		ft_parse(char *file_name);

// read_scene.c
int		read_scene(char *file_name);

// splic_strings.c
char	**split_string(char *str);


// ------------------------------------------------------------: parse/validate
// validate_objects.c
t_validation	validate_object(char **tokens, e_object type);
int				count_tokens(char **tokens);

// validate_ambient_light.c
t_validation	validate_ambient_light(char **tokens);



// ------------------------------------------------------------: utils
// function_protection.c
int		safe_open(char *file_name, int open_flags, ...);
void	*safe_malloc(size_t size, char *func_name);

#endif
