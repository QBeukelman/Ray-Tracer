/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_position.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/25 23:29:33 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/26 00:34:14 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

// -50,0,20
# define DELIMITER ','
# define DELIMITER_COUNT 2

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

static t_vect	*build_position(char **pos_vals)
{
	int		i;
	t_vect	*vec;

	i = 0;
	vec = safe_malloc(sizeof(t_vect), "build_position()");
	while (pos_vals[i])
		i++;
	if (i != 3)
		exit_with_message(E_INVALID_POS, "Too many values", X_FAILURE);
	printf("POS X: %s\n", pos_vals[0]);
	vec->x = ft_strtof(pos_vals[0], NULL);
	vec->y = ft_strtof(pos_vals[1], NULL);
	vec->z = ft_strtof(pos_vals[2], NULL);
	return (vec);
}

t_vect	*parse_position(char *token)
{
	char	**position_values;

	validate_position(token);
	position_values = ft_split(token, DELIMITER);
	if (position_values == NULL)
		exit_with_message(E_SPLIT, token, X_FAILURE);
	return (build_position(position_values));
}
