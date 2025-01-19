/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_point_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:47:11 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/01/19 14:39:50 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

# define POINT_VALUE_LENGTH 3
# define POINT_MAX 1.0
# define DELIMITER_COUNT 1
# define DELIMITER '.'

static bool validate_point_value(char *token)
{
	int		i;

	if (ft_strlen(token) != POINT_VALUE_LENGTH || \
		ft_count_char(token, DELIMITER) != DELIMITER_COUNT)
	{
		show_error(E_INVALID_PT, token);
		return (FAILURE);
	}
	i = 0;
	while (token[i])
	{
		if (!ft_isdigit(token[i]) && token[i] != DELIMITER)
		{
			show_error(E_INVALID_PT, token);
			return (FAILURE);	
		}
		i++;
	}
	return (true);
}

static float build_point_value(char **point_values)
{
	float		integer;
	float		fraction;
	float		result;

	integer = ft_atoi(point_values[0]);
	fraction = (ft_atoi(point_values[1]) / 10.0);
	result = integer + fraction;
	if (result > POINT_MAX)
	{
		show_error(E_INVALID_PT, "< 1.0");
		return (NAN);
	}
	return (result);
}

/**
 * parse_point_value - Parses a point value string and converts it to a float.
 * 
 * @param token: A string containing the point value to parse. The string should
 *               adhere to a specific format defined by the delimiter.
 * 
 * @return: The parsed float value if the input is valid. Returns NAN if the 
 *          validation fails or if an error occurs during parsing.
 * 
 * Edge Cases:
 * - If the token is NULL or doesn't match the expected format, the function
 *   will return NAN.
 * - If memory allocation fails during splitting, the function returns NAN.
 */
float	parse_point_value(char *token)
{
	char	**point_values;
	float	float_value;

	if (validate_point_value(token) == FAILURE)
		return (NAN);

	point_values = ft_split(token, DELIMITER);
	if (point_values == NULL)
	{
		show_error(E_SPLIT, token);
		return (NAN);
	}

	float_value = build_point_value(point_values);
	free_split(point_values);
	return (float_value);
}
