/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:15:00 by qbeukelm          #+#    #+#             */
/*   Updated: 2025/02/28 13:23:51 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int		ft_mlx_init(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init(WIDTH, HEIGHT, "MINI_RT", false);
	if (!mlx_data->mlx)
		return (FAILURE);
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	if (!mlx_data->img)
	{
		mlx_terminate(mlx_data->mlx);
		return (FAILURE);
	}
	return (SUCCESS);
}

void	ft_mlx_terminate(t_mlx_data mlx_data)
{
	mlx_delete_image(mlx_data.mlx, mlx_data.img);
	mlx_terminate(mlx_data.mlx);
}
