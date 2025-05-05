/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_scene.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 19:18:55 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 18:47:16 by quentinbeuk   ########   odam.nl         */
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
	add_object[CONE] = add_cone;
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
	{
		show_error(E_SPLIT, line);
		return (FAILURE);
	}
	object_type = string_to_objects(tokens[0]);
	if (object_type >= NUM_OBJECTS)
	{
		show_error(E_INVALID_OBJ, tokens[0]);
		return (free_split(tokens));
	}
	if (add_object[object_type](scene, tokens) == false)
		return (free_split(tokens));
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
	{
		show_error_const(E_OPEN, file_name);
		return (FAILURE);
	}
	ft_memset(scene, 0, sizeof(t_scene));

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!ft_isspace(line[0]))
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
	scene->rays = NULL;
	
	if (is_valid_filename(file_name) == false)
		return (FAILURE);

	if (parse_scene(scene, file_name) == FAILURE)
	{
		free_object_list(scene->objects);
		return (FAILURE);
	}
	
	if (validate_non_objects(scene) == false)
	{
		free_object_list(scene->objects);
		return (FAILURE);
	}
	scene->is_rendering = false;
	index_objects(scene);
	return (SUCCESS);
}
