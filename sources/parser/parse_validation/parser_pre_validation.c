/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_pre_validation.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 08:28:03 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 21:23:15 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

#define SUFFIX			".rt"
#define SUFFIX_LEN		3

static bool	is_valid_characters(const char *file_name)
{
	int		i;
	int		period_count;

	i = 0;
	period_count = 0;
	while (file_name[i])
	{
		if (file_name[i] == '.')
			period_count++;
		if (!ft_isalnum(file_name[i]) && file_name[i] != '_'
			&& file_name[i] != '/' && file_name[i] != '.')
		{
			return (false);
		}
		i++;
	}
	if (period_count != 1)
		return (false);
	return (true);
}

static bool	is_valid_suffix(const char *file_name, int len)
{
	int		i;

	i = SUFFIX_LEN - 1;
	len--;
	while (i >= 0)
	{
		if (file_name[len] != SUFFIX[i])
			return (false);
		len--;
		i--;
	}
	return (true);
}

/**
 * Validates a file name:
 * - The file name must be at least 4 characters long.
 * - It must contain only alphanumeric characters, underscores ('_'), slashes
 * 		('/'), and exactly one period ('.').
 * - The file name must end with the ".rt" extension.
 *
 * Parameters:
 *   file_name - A pointer to the string representing the file name to validate.
 *
 * Returns:
 *   true if the file name is valid according to the rules; false otherwise.
*/
bool	is_valid_filename(const char *file_name)
{
	int		len;

	len = ft_strlen(file_name);
	if (len < 4)
		return (false);
	if (is_valid_characters(file_name) == false)
	{
		show_error(E_INVALID_FILE, (char *)file_name);
		return (false);
	}
	if (is_valid_suffix(file_name, len) == false)
	{
		show_error(E_INVALID_FILE, (char *)file_name);
		return (false);
	}
	return (true);
}
