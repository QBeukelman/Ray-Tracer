/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:46:26 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/01/19 16:34:15 by qbeukelm         ###   ########.fr       */
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
# define E_ERROR		"Error: "
# define E_OPEN			"Failed to open file: "
# define E_MALLOC		"Memory allocation failed in function: "
# define E_SPLIT		"Failed to split tokens in line: "
# define E_INVALID_OBJ	"Invalid scene object with identifier: "
# define E_TOKEN_COUNT	"Invalid token count for: "
# define E_INVALID_CLR	"Invalid color format: "
# define E_INVALID_PT	"Invalid point value format: "
# define E_INVALID_POS	"Invalid position format: "
# define E_OUT_OF_RANGE	"Value out of range: "


// ------------------------------------------------------------: utils
// error.c
int		show_error(char *error, char *arg);
int		exit_with_message(char *error, char *arg, int exit_code); // ! Do not use

#endif
