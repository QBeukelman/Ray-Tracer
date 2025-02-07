/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:19:51 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/02/07 11:35:47 by qbeukelm         ###   ########.fr       */
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

static t_color	*build_color(char **color_values)
{
	int			i;
	t_color		*color;

	i = 0;
	color = malloc(sizeof(t_color));
	if (color == NULL)
	{
		show_error(E_MALLOC, "build_color()");
		return (NULL);
	}
	while (color_values[i])
		i++;
	if (i != 3)
	{
		show_error(E_INVALID_CLR, TOO_MANY);
		return (NULL);
	}
	if (color_values_in_range(color_values) == FAILURE)
		return (NULL);
	color->r = ft_atoi(color_values[0]);
	color->g = ft_atoi(color_values[1]);
	color->b = ft_atoi(color_values[2]);
	return (color);
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
t_color		*parse_color(char *token)
{
	char		**color_values;
	t_color		*color;

	if (validate_color(token) == FAILURE)
		return (NULL);
	color_values = ft_split(token, DELIMITER);
	if (color_values == NULL)
	{
		show_error(E_SPLIT, token);
		return (NULL);
	}
	color = build_color(color_values);
	free_split(color_values);
	return (color);
}
