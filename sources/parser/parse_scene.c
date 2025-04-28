/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_scene.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 19:18:55 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/28 12:34:16 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	init_add_object_funcs(t_add_func add_object[NUM_OBJECTS])
{
	add_object[AMBIENT_LIGHT] = add_ambient_light;
	add_object[LIGHT] = add_light;
	add_object[CAMERA] = add_camera;
	add_object[SPHERE] = add_sphere;
	add_object[PLANE] = add_plane;
	add_object[CYLINDER] = add_cylinder;
}

static bool	process_line(t_scene *scene, char *line)
{
	char					**tokens;
	e_object				object_type;
	static t_add_func		add_object[NUM_OBJECTS] = {NULL};

	if (add_object[0] == NULL)
		init_add_object_funcs(add_object);
	tokens = split_string(line);
	if (tokens == NULL || !tokens[0])
		exit_with_message(E_SPLIT, line, X_FAILURE);
	object_type = string_to_objects(tokens[0]);
	if (object_type >= NUM_OBJECTS)
		exit_with_message(E_INVALID_OBJ, tokens[0], X_FAILURE);
	if (add_object[object_type](scene, tokens) == false)
	{
		free_split(tokens);
		return (FAILURE);
	}
	free_split(tokens);
	return (SUCCESS);
}

int	count_tokens(char **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

static bool	parse_scene(t_scene *scene, const char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		return (FAILURE);
	ft_memset(scene, 0, sizeof(t_scene));

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != '\n')
		{
			if (process_line(scene, line) == false)
			{
				free(line);
				return (FAILURE);
			}
		}
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
	return (SUCCESS);
}

bool	parser(t_scene *scene, const char *file_name)
{
	// TODO Pre parser checks
	// scene file extension
	if (is_valid_filename(file_name) == false)
		return (false);

	if (parse_scene(scene, file_name) == false)
	{
		free_object_list(scene->objects);
		return (false);
	}
	
	// TODO Post parser checks
	// camera and lights
	if (validate_non_objects(scene) == false)
	{
		free_object_list(scene->objects);
		return (false);
	}

	// TODO Index objects
	index_objects(scene);

	return (true);
}
