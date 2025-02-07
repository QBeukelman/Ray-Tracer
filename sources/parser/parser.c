/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:46:02 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/02/07 13:01:42 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int		count_tokens(char **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

int	ft_parse(char *file_name)
{
	t_scene		*scene;

	// ! 1. check file extension
	scene = build_scene(file_name);
	if (scene == NULL)
	{
		show_error(E_PARSE, file_name);
		return (FAILURE);
	}
	print_scene(scene);
	free_scene(scene);
	return (0);
}
