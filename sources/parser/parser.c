/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 17:46:02 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/10 17:04:09 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	read_scene(char *file_name)
{
	int		fd;
	char	*line;
	char	*scene = NULL;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit_with_message(E_OPEN, file_name, X_FAILURE);

	line = get_next_line(fd);
	ft_strlcat(scene, line, ft_strlen(scene));
	while (line)
	{
		line = get_next_line(fd);
		ft_strlcat(scene, line, ft_strlen(scene));
	}
	printf("%s\n", scene);
}

int	ft_parse(char *file_name)
{
	read_scene(file_name);
	return (0);
}
