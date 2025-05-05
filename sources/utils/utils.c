/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 22:36:47 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/05/05 20:11:30 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	in_range(double value, double min, double max)
{
	if (value < min)
		value = min;
	if (value > max)
		value = max;
	return (value);
}

/**
 * free_split - Frees a NULL-terminated array of strings.
 *
 * This function iterates through a dynamically allocated array of strings
 * (such as one created by ft_split or similar), freeing each individual string
 * and then freeing the array itself.
 *
 * @split: A NULL-terminated array of dynamically allocated strings.
 *
 * Return: Always returns FAILURE (as a constant, likely defined as false or 0),
 *         which allows convenient use in return statements when cleaning up 
 * 		   after an error.
*/
bool	free_split(char **split)
{
	int		i;

	i = 0;
	if (split == NULL)
		return (FAILURE);
	while (split[i])
	{
		free (split[i]);
		i++;
	}
	free (split);
	return (FAILURE);
}

void	free_rays(t_scene *scene)
{
	free(scene->rays[0]);
	free(scene->rays);
}
