/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene_objects.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 00:21:54 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/02/08 01:56:55 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// Do not use global variable here

char	*objects_to_string(e_object object)
{
	const char	*scene_object_keys[7] = {
		"A",
		"L",
		"C",
		"sp",
		"pl",
		"cy",
		"UNKONOWN"
	};

	if (object >= 0 && object < NUM_OBJECTS)
		return ((char *)scene_object_keys[object]);
	return ((char *)scene_object_keys[NUM_OBJECTS]);
}

char	*objects_to_name(e_object object)
{
	static char	*scene_object_names[7] = {
		"Ambient Light",
		"Light",
		"Camera",
		"Sphere",
		"Plane",
		"Cylinder",
		"Unknown Object"
	};

	if (object >= 0 && object < NUM_OBJECTS)
		return ((char *)scene_object_names[object]);
	return ((char *)scene_object_names[NUM_OBJECTS]);
}

e_object	string_to_objects(char *str)
{
	const char	*scene_object_keys[7] = {
		"A",
		"L",
		"C",
		"sp",
		"pl",
		"cy",
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
