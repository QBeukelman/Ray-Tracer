/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 22:36:47 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/03/08 23:31:58 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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

void	free_rays(t_scene *scene)
{
	free(scene->rays[0]);
	free(scene->rays);
}