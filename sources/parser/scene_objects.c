/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene_objects.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 00:21:54 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 20:30:25 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

char	*objects_to_string(t_object_type type)
{
	const char	*scent_object_keys[8] = {
		"A",
		"L",
		"C",
		"sp",
		"pl",
		"cy",
		"cn",
		"UNKONOWN"
	};

	if (type >= 0 && type < NUM_OBJECTS)
		return ((char *)scent_object_keys[type]);
	return ((char *)scent_object_keys[NUM_OBJECTS]);
}

char	*objects_to_name(t_object_type type)
{
	static char	*scent_object_names[8] = {
		"Ambient Light",
		"Light",
		"Camera",
		"Sphere",
		"Plane",
		"Cylinder",
		"Cone",
		"Unknown Object"
	};

	if (type >= 0 && type < NUM_OBJECTS)
		return ((char *)scent_object_names[type]);
	return ((char *)scent_object_names[NUM_OBJECTS]);
}

t_object_type	string_to_objects(char *str)
{
	const char	*scent_object_keys[8] = {
		"A",
		"L",
		"C",
		"sp",
		"pl",
		"cy",
		"cn",
		"UNKONOWN"
	};
	int			i;

	i = 0;
	while (i < NUM_OBJECTS)
	{
		if (ft_strncmp(scent_object_keys[i], str, ft_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (NUM_OBJECTS);
}
