/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:04:52 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/01/10 12:07:54 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

int		parse_int(char *str, int limit)
{
	int		val;

	val = ft_atoi(str);
	if (val >= 0 && val <= limit)
		return (val);
	else
		exit_with_message(E_OUT_OF_RANGE, str, X_FAILURE);
}
