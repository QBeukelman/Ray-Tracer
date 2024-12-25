/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 18:19:51 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/25 23:38:15 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

# define MAX_LEN 11
# define MIN_LEN 5
# define COMMA_COUNT 2
# define RANGE 255
# define DELIMITER ','

static bool validate_color(char *token)
{
	int		len;
	int		i;

	len = ft_strlen(token);
	if (len < MIN_LEN || len > MAX_LEN)
		exit_with_message(E_INVALID_CLR, token, X_FAILURE);
	if (ft_count_char(token, DELIMITER) != COMMA_COUNT)
		exit_with_message(E_INVALID_CLR, token, X_FAILURE);
	i = 0;
	while (token[i])
	{
		if (!ft_isdigit(token[i]) && token[i] != DELIMITER)
			exit_with_message(E_INVALID_CLR, token, X_FAILURE);
		i++;
	}
	return (true);
}

static t_color	*build_color(char **color_values)
{
	int			i;
	t_color		*color;

	i = 0;
	color = safe_malloc(sizeof(t_color), "build_color()");
	while (color_values[i])
		i++;
	if (i != 3)
		exit_with_message(E_INVALID_CLR, "Too many values", X_FAILURE);
	if (ft_atoi(color_values[0]) > RANGE)
		exit_with_message(E_INVALID_CLR, "Out of range", X_FAILURE);
	if (ft_atoi(color_values[1]) > RANGE)
		exit_with_message(E_INVALID_CLR, "Out of range", X_FAILURE);
	if (ft_atoi(color_values[2]) > RANGE)
		exit_with_message(E_INVALID_CLR, "Out of range", X_FAILURE);
	color->r = ft_atoi(color_values[0]);
	color->g = ft_atoi(color_values[1]);
	color->b = ft_atoi(color_values[2]);
	return (color);
}

t_color		*parse_color(char *token)
{
	char		**color_values;
	t_color		*color;

	validate_color(token);
	color_values = ft_split(token, DELIMITER);
	if (color_values == NULL)
		exit_with_message(E_SPLIT, token, X_FAILURE);
	return (build_color(color_values));
}
