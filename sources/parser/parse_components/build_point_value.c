/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_point_value.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/25 20:47:11 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/25 21:23:21 by quentinbeuk   ########   odam.nl         */
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

	if (ft_strlen(token) != POINT_VALUE_LENGTH)
		exit_with_message(E_INVALID_PT, token, X_FAILURE);
	if (ft_count_char(token, DELIMITER) != DELIMITER_COUNT)
		exit_with_message(E_INVALID_PT, token, X_FAILURE);
	i = 0;
	while (token[i])
	{
		if (!ft_isdigit(token[i]) && token[i] != DELIMITER)
			exit_with_message(E_INVALID_PT, token, X_FAILURE);
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
			exit_with_message(E_INVALID_PT, "< 1.0", X_FAILURE);

	return (result);
}

float	parse_point_value(char *token)
{
	char	**point_values;

	validate_point_value(token);
	point_values = ft_split(token, DELIMITER);
	if (point_values == NULL)
		exit_with_message(E_SPLIT, token, X_FAILURE);
	return (build_point_value(point_values));
}
