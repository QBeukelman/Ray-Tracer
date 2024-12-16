/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_objects.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/13 11:21:02 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/13 13:23:21 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_validation	validate_object(char **tokens, e_object type)
{
	switch (type)
	{
		case AMBIENT_LIGHT:
			return (validate_ambient_light(tokens));
		case LIGHT:
			return (SUCCESS);
		case CAMERA:
			return (SUCCESS);
		case SPHERE:
			return (SUCCESS);
		case PLANE:
			return (SUCCESS);
		case CYLINDER:
			return (SUCCESS);
		default:
			return (FAILURE);
	}
}

int		count_tokens(char **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}
