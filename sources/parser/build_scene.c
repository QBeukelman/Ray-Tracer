/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_scene.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 19:18:55 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/16 19:30:38 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	save_object(t_scene *scene, char **tokens, e_object type)
{
	int		i = 0;

	add_object(scene, tokens, type);
	
	while (tokens[i])
	{
		printf("%s\n", tokens[i]);
		i++;
	}
	printf("\n");
	return (true);
}

bool	process_line(t_scene *scene, char *line)
{
	char		**tokens;
	e_object	object_type;

	tokens = split_string(line);
	if (tokens == NULL || !tokens[0])
		exit_with_message(E_SPLIT, line, X_FAILURE);
	
	object_type = string_to_objects(tokens[0]);
	if (object_type >= NUM_OBJECTS)
		exit_with_message(E_INVALID_OBJ, tokens[0], X_FAILURE);

	return (save_object(scene, tokens, object_type));
}

int		build_scene(char *file_name)
{
	int			fd;
	char		*line;
	t_scene		*scene;

	fd = safe_open(file_name, O_RDONLY);
	scene = safe_malloc(sizeof(scene), "build_scene()");
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[0] != '\n')
			process_line(scene, line);
	}
	close (fd);

	printf("R: %d\n", scene->ambi->color->r);
	printf("G: %d\n", scene->ambi->color->g);
	printf("B: %d\n", scene->ambi->color->b);

	return (0);
}
