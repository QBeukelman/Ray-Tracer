/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_scene.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 15:35:51 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/13 13:35:26 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	save_object(char **tokens, e_object type)
{
	int		i = 0;
	while (tokens[i])
	{
		printf("%s\n", tokens[i]);
		i++;
	}
	printf("\n");
	return (true);
}

bool	process_line(char *line)
{
	char		**tokens;
	e_object		object_type;

	tokens = split_string(line);
	if (tokens == NULL || !tokens[0])
		exit_with_message(E_SPLIT, line, X_FAILURE);
	
	object_type = string_to_objects(tokens[0]);
	if (object_type >= NUM_OBJECTS)
		exit_with_message(E_INVALID_OBJ, tokens[0], X_FAILURE);

	return (save_object(tokens, object_type));
}

int		read_scene(char *file_name)
{
	int		fd;
	char	*line;

	fd = safe_open(file_name, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[0] != '\n')
			process_line(line);
	}
	close (fd);
	return (0);
}
