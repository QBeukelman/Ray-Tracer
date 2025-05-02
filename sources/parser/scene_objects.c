/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:21:54 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/05/02 14:34:08 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// Do not use global variable here

char	*objects_to_string(e_object object)
{
	const char	*scene_object_keys[8] = {
		"A",
		"L",
		"C",
		"sp",
		"pl",
		"cy",
		"cn",
		"UNKONOWN"
	};

	if (object >= 0 && object < NUM_OBJECTS)
		return ((char *)scene_object_keys[object]);
	return ((char *)scene_object_keys[NUM_OBJECTS]);
}

char	*objects_to_name(e_object object)
{
	static char	*scene_object_names[8] = {
		"Ambient Light",
		"Light",
		"Camera",
		"Sphere",
		"Plane",
		"Cylinder",
		"Cone",
		"Unknown Object"
	};

	if (object >= 0 && object < NUM_OBJECTS)
		return ((char *)scene_object_names[object]);
	return ((char *)scene_object_names[NUM_OBJECTS]);
}

e_object	string_to_objects(char *str)
{
	const char	*scene_object_keys[8] = {
		"A",
		"L",
		"C",
		"sp",
		"pl",
		"cy",
		"cn"
		"UNKONOWN"
	};
	int			i;

	i = 0;
	while (i < NUM_OBJECTS)
	{
		if (ft_strncmp(scene_object_keys[i], str, ft_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (NUM_OBJECTS);
}
