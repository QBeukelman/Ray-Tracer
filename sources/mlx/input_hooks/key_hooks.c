/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:01:14 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/02/28 13:13:03 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	ft_keyhook(mlx_key_data_t keydata, t_all_data *all_data)
{
	if (keydata.key == MLX_KEY_ENTER && keydata.action == MLX_RELEASE)
		key_enter(all_data->mlx_data, all_data->scene);

	// TODO: Clean exit method
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		exit(0);
}
