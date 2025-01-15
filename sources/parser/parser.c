/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:46:02 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/01/10 15:13:24 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_parse(char *file_name)
{
	t_scene		*scene;

	// ! 1. check file extension
	scene = build_scene(file_name);
	print_scene(scene);
	scene->planes = NULL;
	free (scene);

	return (0);
}
