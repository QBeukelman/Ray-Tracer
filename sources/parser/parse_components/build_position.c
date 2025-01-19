/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:29:33 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/01/19 15:51:08 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

# define DELIMITER ','
# define DELIMITER_COUNT 2

static bool	validate_limit(float val, float limit)
{
	if (val <= limit && val >= (limit * -1))
		return (true);
	return (false);
}

static bool validate_limits(char **pos_vals, float limit)
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

static bool		validate_position(char *token)
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
	return (true);
}

static t_vect	*build_position(char **pos_vals, float limit)
{
	int		i;
	t_vect	*vec;
	
	i = 0;
	vec = malloc(sizeof(t_vect));
	if (vec == NULL)
		return (NULL);
	while (pos_vals[i])
		i++;
	if (i != 3)
	{
		show_error(E_INVALID_POS, "Too many values");
		return (NULL);
	}	
	if (validate_limits(pos_vals, limit) == FAILURE)
		return (NULL);
	vec->x = ft_strtof(pos_vals[0], NULL);
	vec->y = ft_strtof(pos_vals[1], NULL);
	vec->z = ft_strtof(pos_vals[2], NULL);
	return (vec);
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
t_vect	*parse_position(char *token, float limit)
{
	char	**position_values;
	t_vect	*position;

	if (validate_position(token) == FAILURE)
		return (NULL);
	position_values = ft_split(token, DELIMITER);
	if (position_values == NULL)
	{
		show_error(E_SPLIT, token);
		return (NULL);
	}
	position = build_position(position_values, limit);
	free_split(position_values);
	return (position);
}
