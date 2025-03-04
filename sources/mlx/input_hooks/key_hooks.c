/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/28 11:01:14 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/03/03 19:28:09 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	ft_keyhook(mlx_key_data_t keydata, void *data)
{
	t_all_data	*all_data;

	all_data = (t_all_data *) data;
	if (keydata.key == MLX_KEY_ENTER && keydata.action == MLX_RELEASE)
		key_enter(all_data->mlx_data, all_data->scene);

	// TODO: Clean exit method
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		exit(0);
}
