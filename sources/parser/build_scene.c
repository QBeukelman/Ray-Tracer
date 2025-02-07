/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:18:55 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/02/07 13:12:37 by qbeukelm         ###   ########.fr       */
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

static bool faild_processing_line(char **tokens, char *line, char *error)
{
	show_error(error, line);
	free_split(tokens);
	free(line);
	return (FAILURE);
}

static bool	line_to_object(t_scene *scene, char *line)
{
	char		**tokens;
	e_object	object_type;
	bool		status;

	tokens = split_string(line);
	if (tokens == NULL || !tokens[0])
		return (faild_processing_line(tokens, line, E_SPLIT));
	
	object_type = string_to_objects(tokens[0]);
	if (object_type >= NUM_OBJECTS)
		return (faild_processing_line(tokens, line, E_INVALID_OBJ));

	status = add_object(scene, tokens, object_type);
	free_split(tokens);
	free (line);
	return (status);
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
	return (scene);
}

static t_scene	*file_to_scene(int fd, t_scene *scene)
{
	char		*line;

	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[0] != '\n')
		{
			if (line_to_object(scene, line) == FAILURE)
			{
				free_scene(scene);
				scene = NULL;
				break ;
			}
		}
		else
			free (line);
	}
	return (scene);
}

t_scene		*build_scene(char *file_name)
{
	int			fd;
	t_scene		*scene;

	fd = safe_open(file_name, O_RDONLY);
	scene = init_scene();
	if (scene == NULL)
	{
		close (fd);
		return (NULL);
	}
	scene = file_to_scene(fd, scene);
	close (fd);
	return (scene);
}
