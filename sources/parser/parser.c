/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:46:02 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/01/19 17:16:18 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_parse(char *file_name)
{
	t_scene		*scene;

	// ! 1. check file extension
	scene = build_scene(file_name);
	if (scene == NULL)
	{
		show_error("Failed to open scene: ", file_name);
		return (FAILURE);
	}
	print_scene(scene);
	free_scene(scene);
	return (0);
}
