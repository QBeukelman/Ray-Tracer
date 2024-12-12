/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 22:00:28 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/11 23:51:34 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int skip_spaces(char *str, int i, int len)
{
	while (i < len)
	{
		if (!ft_isspace(str[i]))
			break ;
		i++;
	}
	return (i);
}

int	count_substrings(char *str, int len)
{
	int		i;
	int		i_check;
	int		count;

	i = 0;
	count = 0;
	while (i < len)
	{
		i = skip_spaces(str, i, len);
		i_check = i;
		while (i < len)
		{
			if (ft_isspace(str[i]))
				break ;
			i++;
		}

		if (i > i_check)
			count++;
	}
	return (count);
}

static int	extract_word(char *str, char *buffer, int i, int len)
{
	int		j;

	j = 0;
	while (i < len)
	{
		if (ft_isspace(str[i]))
			break ;
		buffer[j] = str[i];
		j++;
		i++;
	}
	buffer[j] = '\0';
	return (i);
}

static char **assign_strings(char **split, char *str, int len)
{
	int		i;
	int		string_index;
	char	buffer[BUFFER_SIZE];

	i = 0;
	string_index = 0;
	while (i < len)
	{
		i = skip_spaces(str, i, len);
		i = extract_word(str, buffer, i, len);
		if (buffer[0] != '\0')
		{
			split[string_index] = safe_malloc(sizeof(char *) \
				* ft_strlen(buffer) + 1, "assign_substrings()");
			split[string_index] = ft_strdup(buffer);
			string_index++;
		}
	}
	split[string_index] = 0;
	return (split);
}

char **split_string(char *str)
{
	int		len;
    int     count;
    char    **split;

	len = ft_strlen(str);
    count = count_substrings(str, len);
	split = safe_malloc((sizeof(char *) * count + 1), "split_string()");
	split = assign_strings(split, str, len);
    return (split);
}
