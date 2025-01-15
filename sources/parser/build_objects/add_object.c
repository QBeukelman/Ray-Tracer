/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:21:02 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/01/10 13:11:11 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

bool	add_object(t_scene *scene, char **tokens, e_object type)
{
	switch (type)
	{
		case AMBIENT_LIGHT:
			return (add_ambient_light(scene, tokens));
		case LIGHT:
			return (add_light(scene, tokens));
		case CAMERA:
			return (add_camera(scene, tokens));
		case SPHERE:
			return (SUCCESS);
		case PLANE:
			return (add_plane(scene, tokens));
		case CYLINDER:
			return (SUCCESS);
		default:
			return (FAILURE);
	}

}

int		count_tokens(char **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}
