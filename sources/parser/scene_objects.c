/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene_objects.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 00:21:54 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/12 01:03:03 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// Do not use global variable here
static char *scene_objects[] = {
	"A",
	"L",
	"C",
	"sp",
	"pl",
	"cy",
	"UNKONOWN"
};

char	*objects_to_string(Objects object)
{
	if (object >= 0 && object < NUM_OBJECTS)
		return (scene_objects[object]);
	return (scene_objects[NUM_OBJECTS]);
}

Objects		string_to_objects(char *str)
{
	int		i;

	i = 0;
	while (i < NUM_OBJECTS)
	{
		if (ft_strncmp(scene_objects[i], str, ft_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (NUM_OBJECTS);
}
