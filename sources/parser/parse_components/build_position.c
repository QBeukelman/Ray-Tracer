/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_position.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/25 23:29:33 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 17:34:58 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

#define DELIMITER ','
#define DELIMITER_COUNT 2

static bool	validate_limit(float val, float limit)
{
	if (val <= limit && val >= (limit * -1))
		return (true);
	return (false);
}

static bool	validate_limits(char **pos_vals, float limit)
{
	if (limit != 0)
	{
		if (validate_limit(ft_strtof(pos_vals[0], NULL), limit) == false)
		{
			show_error(E_OUT_OF_RANGE, pos_vals[0]);
			return (FAILURE);
		}
		if (validate_limit(ft_strtof(pos_vals[1], NULL), limit) == false)
		{
			show_error(E_OUT_OF_RANGE, pos_vals[1]);
			return (FAILURE);
		}
		if (validate_limit(ft_strtof(pos_vals[2], NULL), limit) == false)
		{
			show_error(E_OUT_OF_RANGE, pos_vals[2]);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

static bool	validate_position(char *token)
{
	int		i;

	if (ft_count_char(token, DELIMITER) != DELIMITER_COUNT)
	{
		show_error(E_INVALID_POS, token);
		return (FAILURE);
	}
	i = 0;
	while (token[i])
	{
		if (!ft_isdigit(token[i]) && token[i] != DELIMITER)
		{
			if (token[i] != '-' && token[i] != '.')
			{
				show_error(E_INVALID_POS, token);
				return (FAILURE);
			}
		}
		i++;
	}
	return (SUCCESS);
}

static bool	build_position(t_vector *vector, char **pos_vals, float limit)
{
	int		i;

	i = 0;
	while (pos_vals[i])
		i++;
	if (i != 3)
	{
		show_error(E_INVALID_POS, "Too many values");
		return (FAILURE);
	}
	if (validate_limits(pos_vals, limit) == FAILURE)
		return (FAILURE);
	vector->x = ft_strtof(pos_vals[0], NULL);
	vector->y = ft_strtof(pos_vals[1], NULL);
	vector->z = ft_strtof(pos_vals[2], NULL);
	return (SUCCESS);
}

/**
 * parse_position - Parses a string representing a 3D position and validates it.
 * 
 * @param token: A string containing position values separated by a predefined delimiter.
 *               The token should consist of exactly three float values (e.g., "1.0,2.0,3.0").
 * @param limit: A float value specifying the maximum allowable magnitude for each position component.
 * 
 * @return A pointer to a `t_vect` structure containing the parsed x, y, and z coordinates, 
 *         or NULL if any validation or parsing fails.
 * 
 * Errors:
 * - If the token format is invalid, `validate_position()` handles error logging.
 * - If `ft_split()` fails, an error is logged with `E_SPLIT` and the input token.
 * - If `build_position()` encounters an error, it logs the appropriate message internally.
 */
bool	parse_position(t_vector *vector, char *token, float limit)
{
	char	**position_values;

	if (validate_position(token) == FAILURE)
	{
		return (FAILURE);
	}
	position_values = ft_split(token, DELIMITER);
	if (position_values == NULL)
	{
		show_error(E_SPLIT, token);
		return (FAILURE);
	}
	if (build_position(vector, position_values, limit) == false)
	{
		free_split(position_values);
		return (FAILURE);
	}
	free_split(position_values);
	return (SUCCESS);
}
