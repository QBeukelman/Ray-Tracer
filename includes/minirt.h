/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:23 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/10 14:59:31 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

#include "libft/includes/libft.h"
#include "errors.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>

// -----------------------------------: colors
# define C_YELLOW "\033[1;33m"
# define C_RED "\x1B[1;31m"
# define RESET_COLOR "\033[0m"


// -----------------------------------: parse
// parser.c
int	ft_parse(char *file_name);

#endif
