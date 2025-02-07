/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 12:04:52 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/02/07 12:39:34 by hein          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

# define FOV_LIMIT 180

/**
 * @brief Parses a string into an integer and checks if the value is within the specified range.
 * 
 * This function converts a string to an integer using the `ft_atoi` function, and then checks if the 
 * resulting integer is within the range [0, limit]. If the value is within this range, it returns the integer.
 * If the value is outside this range, it triggers an error by calling `show_error` with an out-of-range error 
 * and returns -1.
 *
 * @param str The string to be converted to an integer.
 * @param limit The upper limit for the valid range of the parsed integer.
 * 
 * @return The parsed integer if it is within the range [0, limit], otherwise -1.
 */
// int		parse_int(int fov, char *str)
// {
// 	int		val;

// 	val = ft_atoi(str);
// 	if (val >= 0 && val <= FOV_LIMIT)
// 		return (val);
// 	else
// 	{
// 		show_error(E_OUT_OF_RANGE, str);
// 		return (-1);
// 	}
// }

bool	parse_int(int fov, char *str)
{
	fov = ft_atoi(str);
	if (fov >= 0 && fov <= FOV_LIMIT)
		return (true);
	show_error(E_OUT_OF_RANGE, str);
	return (false);
}
