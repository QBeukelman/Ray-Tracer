/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:18 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/12 00:56:03 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef enum {
	AMBIENT_LIGHT,
	LIGHT,
	CAMERA,
	SPHERE,
	PLANE,
	CYLINDER,
	NUM_OBJECTS
} Objects;

// ------------------------------------------------------------: parse
// scene_objects.c
char		*objects_to_string(Objects object);
Objects		string_to_objects(char *str);
