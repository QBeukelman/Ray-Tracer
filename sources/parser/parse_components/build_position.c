/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:29:33 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/01/17 18:46:47 by qbeukelm         ###   ########.fr       */
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

static bool		validate_position(char *token)
{
	int		i;

	if (ft_count_char(token, DELIMITER) != DELIMITER_COUNT)
		exit_with_message(E_INVALID_POS, token, X_FAILURE);
	i = 0;
	while (token[i])
	{
		if (!ft_isdigit(token[i]) && token[i] != DELIMITER)
			if (token[i] != '-' && token[i] != '.')
				exit_with_message(E_INVALID_POS, token, X_FAILURE);
		i++;
	}
	return (true);
}

static t_vect	*build_position(char **pos_vals, float limit)
{
	int		i;
	t_vect	*vec;
	
	i = 0;
	vec = safe_malloc(sizeof(t_vect), "build_position()");
	while (pos_vals[i])
		i++;
	if (i != 3)
		exit_with_message(E_INVALID_POS, "Too many values", X_FAILURE);
	if (limit != 0)
	{
		if (validate_limit(ft_strtof(pos_vals[0], NULL), limit) == false)
			exit_with_message(E_OUT_OF_RANGE, pos_vals[0], X_FAILURE);
		if (validate_limit(ft_strtof(pos_vals[1], NULL), limit) == false)
			exit_with_message(E_OUT_OF_RANGE, pos_vals[0], X_FAILURE);
		if (validate_limit(ft_strtof(pos_vals[2], NULL), limit) == false)
			exit_with_message(E_OUT_OF_RANGE, pos_vals[0], X_FAILURE);
	}
	vec->x = ft_strtof(pos_vals[0], NULL);
	vec->y = ft_strtof(pos_vals[1], NULL);
	vec->z = ft_strtof(pos_vals[2], NULL);
	return (vec);
}

/*
	Limit: 0.0 is no limit
*/
t_vect	*parse_position(char *token, float limit)
{
	char	**position_values;

	validate_position(token);
	position_values = ft_split(token, DELIMITER);
	if (position_values == NULL)
		exit_with_message(E_SPLIT, token, X_FAILURE);
	return (build_position(position_values, limit));
}
