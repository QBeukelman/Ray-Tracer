/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_scene.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 19:18:55 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/02/08 01:15:21 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	process_line(t_scene *scene, char *line)
{
	char					**tokens;
	e_object				object_type;
	static const t_add_func	add_object[NUM_OBJECTS] = {add_ambient_light,
		add_light, add_camera, add_sphere, add_plane, add_cylinder};

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

bool	parse_scene(t_scene *scene, char *file_name)
{
	int		fd;
	char	*line;

	fd = safe_open(file_name, O_RDONLY);
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
