/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:02 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/25 22:18:02 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_parse(char *file_name)
{
	t_scene		*scene;
	// 1. check file extension

	scene = build_scene(file_name);

	print_scene(scene);

	return (0);
}
