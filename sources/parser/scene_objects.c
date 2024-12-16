/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene_objects.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 00:21:54 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/13 13:33:51 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// Do not use global variable here
static char *scene_object_keys[] = {
	"A",
	"L",
	"C",
	"sp",
	"pl",
	"cy",
	"UNKONOWN"
};

static char *scene_object_names[] = {
	"Ambient Light",
	"Light",
	"Camera",
	"Sphere",
	"Plane",
	"Cylinder",
	"Unknown Object"
};

char	*objects_to_string(e_object object)
{
	if (object >= 0 && object < NUM_OBJECTS)
		return (scene_object_keys[object]);
	return (scene_object_keys[NUM_OBJECTS]);
}

char	*objects_to_name(e_object object)
{
	if (object >= 0 && object < NUM_OBJECTS)
		return (scene_object_names[object]);
	return (scene_object_names[NUM_OBJECTS]);
}

e_object		string_to_objects(char *str)
{
	int		i;

	i = 0;
	while (i < NUM_OBJECTS)
	{
		if (ft_strncmp(scene_object_keys[i], str, ft_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (NUM_OBJECTS);
}
