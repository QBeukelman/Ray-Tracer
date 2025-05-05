/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:26 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 20:16:42 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum e_validation
{
	FAILURE,
	SUCCESS
}	t_validation;

// ------------------------------------------------------------: error codes
# define X_FAILURE		EXIT_FAILURE

// ------------------------------------------------------------: error messages
# define E_ERROR		"Error: \n"
# define E_PROGRAM_IN	"Invalid program input."
# define E_OPEN			"Failed to open file: "
# define E_MALLOC		"Memory allocation failed in function: "
# define E_PARSE		"Could not parse scene: "
# define E_SPLIT		"Failed to split tokens in line: "
# define E_INVALID_OBJ	"Invalid scene object with identifier: "
# define E_TOKEN_COUNT	"Invalid token count for: "
# define E_INVALID_CLR	"Invalid color format: "
# define E_INVALID_PT	"Invalid point value format: "
# define E_INVALID_POS	"Invalid position format: "
# define E_INVALID_C	"Invalid character found: "
# define E_OUT_OF_RANGE	"Value out of range: "
# define E_OBJ_COUNT	"Invalid object count: "
# define E_INVALID_FILE	"Invalid file name: "
# define E_MISSING_OBJ	"Scene must contain required object(s): "
# define E_DUP_OBJ		"Scene contains duplicate object: "


// ------------------------------------------------------------: utils
// error.c
int		show_error(char *error, char *arg);
int		show_error_const(char *error, const char *arg);

#endif
