/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 18:19:51 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/02/07 02:25:39 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

# define MAX_LEN 11
# define MIN_LEN 5
# define COMMA_COUNT 2
# define RANGE 255
# define DELIMITER ','
# define OUT_RANGE "Out of range."
# define TOO_MANY "Too many values"

static bool validate_color(char *token)
{
	int		len;
	int		i;

	len = ft_strlen(token);
	if (len < MIN_LEN || len > MAX_LEN || \
		ft_count_char(token, DELIMITER) != COMMA_COUNT)
	{
		show_error(E_INVALID_CLR, token);
		return (FAILURE);
	}
	i = 0;
	while (token[i])
	{
		if (!ft_isdigit(token[i]) && token[i] != DELIMITER)
		{
			show_error(E_INVALID_CLR, token);
			return (NULL);
		}
		i++;
	}
	return (true);
}

static bool	color_values_in_range(char **color_values)
{
	if (ft_atoi(color_values[0]) > RANGE)
	{
		show_error(E_INVALID_CLR, OUT_RANGE);
		return (FAILURE);
	}
	if (ft_atoi(color_values[1]) > RANGE)
	{
		show_error(E_INVALID_CLR, OUT_RANGE);
		return (FAILURE);
	}
	if (ft_atoi(color_values[2]) > RANGE)
	{
		show_error(E_INVALID_CLR, OUT_RANGE);
		return (FAILURE);
	}
	return (SUCCESS);
}

static bool	build_color(t_object *object, char **color_values)
{
	int			i;

	i = 0;
	while (color_values[i])
		i++;
	if (i != 3)
	{
		show_error(E_INVALID_CLR, TOO_MANY);
		return (false);
	}
	if (color_values_in_range(color_values) == FAILURE)
	{
		return (false);
	}
	object->color.r = ft_atoi(color_values[0]);
	object->color.g = ft_atoi(color_values[1]);
	object->color.b = ft_atoi(color_values[2]);
	return (true);
}

/**
 * @brief Allocates memory and constructs a `t_color` structure from an array of color values.
 * 
 * @param color_values An array of strings representing the color components, where:
 *                     color_values[0] is red, color_values[1] is green, and color_values[2] is blue.
 * 
 * @return A pointer to a `t_color` structure if successful, or `NULL` if an error occurs.
 * 
 * Error Handling:
 * - If memory allocation fails, an error message is shown and `NULL` is returned.
 * - If the number of color values is not exactly 3, an error message is shown and `NULL` is returned.
 * - If any color value is out of the valid range, the function returns `FAILURE`.
 */
bool	parse_color(t_object *object, char *token)
{
	char		**color_values;

	if (validate_color(token) == FAILURE)
		return (false);
	color_values = ft_split(token, DELIMITER);
	if (color_values == NULL)
	{
		show_error(E_SPLIT, token);
		return (false);
	}
	if (build_color(object, color_values) == false)
	{
		free_split(color_values);
		return (false);
	}
	free_split(color_values);
	return (true);
}
