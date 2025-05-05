/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 12:04:52 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/05/05 17:03:32 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

#define VAL_LIMIT 180

static bool	is_valid(char *str)
{
	int i = 0;

	if (!str || !str[0])
		return (false);
	if (str[0] == '-')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Parses and validates an integer from a string input.
 *
 * This function first checks if the input string contains only valid characters
 * (digits and an optional leading minus sign) using `is_valid()`. If the string
 * passes this check, it is then converted to an integer using `ft_atoi()`.
 * The parsed value is validated to ensure it lies within the inclusive range [0, VAL_LIMIT].
 * 
 * If both the format and the range are valid, the result is stored in `*val` and the function
 * returns true. If the format is invalid, it calls `show_error` with `E_INVALID_C`.
 * If the value is out of range, it calls `show_error` with `E_OUT_OF_RANGE`.
 *
 * @param val Pointer to an integer where the parsed value will be stored if valid.
 * @param str The string to be parsed into an integer.
 *
 * @return true if the input string is valid and within range, false otherwise.
 */
bool	parse_int(int *val, char *str)
{
	long	result;
	if (is_valid(str) == false)
	{
		show_error(E_INVALID_C, str);
		return (false);
	}
	result = ft_strtol(str);
	if (result > INT_MAX || result < INT_MIN)
	{
		show_error(E_OUT_OF_RANGE, str);
		return (false);
	}
	*val = (int)result;
	if (*val >= 0 && *val <= VAL_LIMIT)
		return (true);
	show_error(E_OUT_OF_RANGE, str);
	return (false);
}
