/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:36:47 by hesmolde          #+#    #+#             */
/*   Updated: 2025/02/22 12:46:23 by qbeukelm         ###   ########.fr       */
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
