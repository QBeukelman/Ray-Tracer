/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:26 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/28 10:20:16 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum
{
	FAILURE,
	SUCCESS
}	e_validation;

// ------------------------------------------------------------: error codes
# define X_FAILURE		EXIT_FAILURE

// ------------------------------------------------------------: error messages
# define E_ERROR		"Error: "
# define E_OPEN			"Failed to open file: "
# define E_MALLOC		"Memory allocation failed in function: "
# define E_PARSE		"Could not parse scene: "
# define E_SPLIT		"Failed to split tokens in line: "
# define E_INVALID_OBJ	"Invalid scene object with identifier: "
# define E_TOKEN_COUNT	"Invalid token count for: "
# define E_INVALID_CLR	"Invalid colour format: "
# define E_INVALID_PT	"Invalid point value format: "
# define E_INVALID_POS	"Invalid position format: "
# define E_OUT_OF_RANGE	"Value out of range: "
# define E_OBJ_COUNT	"Invalid object count: "
# define E_INVALID_FILE	"Invalid file name: "
# define E_MISSING_OBJ	"Scene must contain: "


// ------------------------------------------------------------: utils
// error.c
int		show_error(char *error, char *arg);
int		exit_with_message(char *error, char *arg, int exit_code); // ! Do not use

#endif
