/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   function_protection.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 13:06:48 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/11 15:33:18 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int		safe_open(char *file_name, int open_flags, ...)
{
	int	fd;

	fd = open(file_name, open_flags);
	if (fd < 0)
		exit_with_message(E_OPEN, file_name, X_FAILURE);
	return (fd);
}

void	*safe_malloc(size_t size, char *func_name)
{
	void	*ptr;

	ptr = NULL;
	ptr = malloc(size);
	if (ptr == NULL)
	{
		free (ptr);
		exit_with_message(E_MALLOC, func_name, EXIT_FAILURE);
	}
	return (ptr);
}
