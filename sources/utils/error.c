/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 14:32:23 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 20:16:49 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	show_error(char *error, char *arg)
{
	write(STDERR_FILENO, C_RED, ft_strlen(C_RED));
	write(STDERR_FILENO, E_ERROR, ft_strlen(E_ERROR));
	write(STDERR_FILENO, error, ft_strlen(error));
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, RESET_COLOR, ft_strlen(RESET_COLOR));
	write(STDERR_FILENO, "\n", 1);
	return (FAILURE);
}

int	show_error_const(char *error, const char *arg)
{
	write(STDERR_FILENO, C_RED, ft_strlen(C_RED));
	write(STDERR_FILENO, E_ERROR, ft_strlen(E_ERROR));
	write(STDERR_FILENO, error, ft_strlen(error));
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, RESET_COLOR, ft_strlen(RESET_COLOR));
	write(STDERR_FILENO, "\n", 1);
	return (FAILURE);
}
