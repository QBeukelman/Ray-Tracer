/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 22:36:47 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/02/08 02:03:09 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	free_split(char **split)
{
	int		i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
	{
		free (split[i]);
		i++;
	}
	free (split);
}
