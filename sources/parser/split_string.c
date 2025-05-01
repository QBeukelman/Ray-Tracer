/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 22:00:28 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/04/28 22:47:09 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	skip_spaces(char *str, int i, int len)
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

static char	**assign_strings(char **split, char *str, int len)
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
			split[string_index] = ft_strdup(buffer);
			string_index++;
		}
	}
	split[string_index] = NULL;
	return (split);
}

char	**split_string(char *str)
{
	int		len;
	int		count;
	char	**split;

	len = ft_strlen(str);
	count = count_substrings(str, len);
	split = malloc((sizeof(char *) * (count + 1)));
	if (split == NULL)
	{
		show_error(E_MALLOC, "split_string()");
		return (NULL);
	}
	split = assign_strings(split, str, len);
	return (split);
}
