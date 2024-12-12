/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:26 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/11 13:08:17 by quentinbeuk   ########   odam.nl         */
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
# define E_ERROR	"Error: "
# define E_OPEN		"Failed to open file: "
# define E_MALLOC	"Memory allocation failed in function: "


// ------------------------------------------------------------: utils
// error.c
int	show_error(char *error, char *arg);
int	exit_with_message(char *error, char *arg, int exit_code);

#endif
