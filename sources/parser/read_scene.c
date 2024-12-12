/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_scene.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 15:35:51 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/12 00:59:10 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	process_line(char *line)
{
	char	**tokens;
	int		i = 0;

	tokens = split_string(line);
	printf("Str to Obj: %d\n", string_to_objects(tokens[0]));
	while (tokens[i])
	{
		printf("%s\n", tokens[i]);
		i++;
	}
	printf("\n");

	return (true);
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
