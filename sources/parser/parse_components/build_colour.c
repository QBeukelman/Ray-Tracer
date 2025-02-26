/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_colour.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/23 11:08:38 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/02/23 11:09:57 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

#define MAX_LEN 11
#define MIN_LEN 5
#define COMMA_COUNT 2
#define RANGE 255
#define DELIMITER ','
#define OUT_RANGE "Out of range."
#define TOO_MANY "Too many values"

static bool	validate_colour(char *token)
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

static bool	colour_values_in_range(char **colour_values)
{
	if (ft_atoi(colour_values[0]) > RANGE)
	{
		show_error(E_INVALID_CLR, OUT_RANGE);
		return (FAILURE);
	}
	if (ft_atoi(colour_values[1]) > RANGE)
	{
		show_error(E_INVALID_CLR, OUT_RANGE);
		return (FAILURE);
	}
	if (ft_atoi(colour_values[2]) > RANGE)
	{
		show_error(E_INVALID_CLR, OUT_RANGE);
		return (FAILURE);
	}
	return (SUCCESS);
}

static bool	build_colour(t_colour *colour, char **colour_values)
{
	int		i;

	i = 0;
	while (colour_values[i])
		i++;
	if (i != 3)
	{
		show_error(E_INVALID_CLR, TOO_MANY);
		return (false);
	}
	if (colour_values_in_range(colour_values) == FAILURE)
	{
		return (false);
	}
	colour->r = ft_atoi(colour_values[0]);
	colour->g = ft_atoi(colour_values[1]);
	colour->b = ft_atoi(colour_values[2]);
	return (true);
}

/**
 * @brief Allocates memory and constructs a `t_colour` structure from an array of colour values.
 * 
 * @param colour_values An array of strings representing the colour components, where:
 *                     colour_values[0] is red, colour_values[1] is green, and colour_values[2] is blue.
 * 
 * @return A pointer to a `t_colour` structure if successful, or `NULL` if an error occurs.
 * 
 * Error Handling:
 * - If memory allocation fails, an error message is shown and `NULL` is returned.
 * - If the number of colour values is not exactly 3, an error message is shown and `NULL` is returned.
 * - If any colour value is out of the valid range, the function returns `FAILURE`.
 */
bool	parse_colour(t_colour *colour, char *token)
{
	char	**colour_values;

	if (validate_colour(token) == FAILURE)
		return (false);
	colour_values = ft_split(token, DELIMITER);
	if (colour_values == NULL)
	{
		show_error(E_SPLIT, token);
		return (false);
	}
	if (build_colour(colour, colour_values) == false)
	{
		free_split(colour_values);
		return (false);
	}
	free_split(colour_values);
	return (true);
}
