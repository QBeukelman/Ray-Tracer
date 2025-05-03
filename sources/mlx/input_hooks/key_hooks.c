/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/28 11:01:14 by qbeukelm      #+#    #+#                 */
/*   Updated: 2025/05/03 13:05:41 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	ft_keyhook(mlx_key_data_t keydata, void *data)
{
	t_all_data	*all_data;

	all_data = (t_all_data *) data;
	if (keydata.key == MLX_KEY_ENTER && keydata.action == MLX_RELEASE)
		enter_key_hook(all_data->mlx_data, all_data->scene);
	
	// Select object
	if (keydata.key == MLX_KEY_RIGHT_BRACKET && keydata.action == MLX_RELEASE)
		right_bracket_key_hook(all_data->mlx_data, all_data->scene);
	if (keydata.key == MLX_KEY_LEFT_BRACKET && keydata.action == MLX_RELEASE)
		left_bracket_key_hook(all_data->mlx_data, all_data->scene);

	// Select property
	if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_RELEASE)
		tab_key_hook(all_data->mlx_data, all_data->scene);

	// Select vector
	if (keydata.key == MLX_KEY_X && keydata.action == MLX_RELEASE)
		x_key_hook(all_data->mlx_data, all_data->scene);
	if (keydata.key == MLX_KEY_Y && keydata.action == MLX_RELEASE)
		y_key_hook(all_data->mlx_data, all_data->scene);
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_RELEASE)
		z_key_hook(all_data->mlx_data, all_data->scene);
	
	// Increment value
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		up_key_hook(all_data->mlx_data, all_data->scene);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		down_key_hook(all_data->mlx_data, all_data->scene);

	// TODO: Clean exit method
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		exit(0);
}
