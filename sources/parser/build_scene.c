/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:18:55 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/01/19 17:14:53 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	add_object(t_scene *scene, char **tokens, e_object type)
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
			return (add_sphere(scene, tokens));
		case PLANE:
			return (add_plane(scene, tokens));
		case CYLINDER:
			return (add_cylinder(scene, tokens));
		default:
			return (FAILURE);
	}
}

static bool	process_line(t_scene *scene, char *line)
{
	char		**tokens;
	e_object	object_type;

	tokens = split_string(line);
	if (tokens == NULL || !tokens[0])
		exit_with_message(E_SPLIT, line, X_FAILURE);
	
	object_type = string_to_objects(tokens[0]);
	if (object_type >= NUM_OBJECTS)
		exit_with_message(E_INVALID_OBJ, tokens[0], X_FAILURE);

	add_object(scene, tokens, object_type);
	free_split(tokens);
	free (line);
	return (SUCCESS);
}

static t_scene		*init_scene(void)
{
	t_scene		*scene;

	scene = malloc(sizeof(t_scene));
	if (scene == NULL)
	{
		show_error(E_MALLOC, "build_scene()");
		return (NULL);
	} 
	scene->ambi = NULL;
	scene->camera = NULL;
	scene->light = NULL;
	scene->planes = NULL;
	scene->spheres = NULL;
	scene->cylinders = NULL;
}

int		count_tokens(char **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

t_scene		*build_scene(char *file_name)
{
	int			fd;
	char		*line;
	t_scene		*scene;

	fd = safe_open(file_name, O_RDONLY);
	scene = init_scene();
	if (scene == NULL)
	{
		close (fd);
		return (NULL);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[0] != '\n')
			process_line(scene, line);
		else
			free (line);
	}
	close (fd);
	return (scene);
}
