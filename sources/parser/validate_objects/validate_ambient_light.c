/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_ambient_light.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/13 11:21:56 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/13 13:34:54 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

t_validation	validate_ambient_light(char **tokens)
{
	if (count_tokens(tokens) != TOKEN_COUNT_A)
		exit_with_message(E_TOKEN_COUNT, objects_to_name(AMBIENT_LIGHT), X_FAILURE);
	return (SUCCESS);
}
