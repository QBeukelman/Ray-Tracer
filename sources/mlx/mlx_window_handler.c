/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_window_handler.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 12:25:37 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/05/05 19:25:30 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_mlx_init(t_mlx_data *mlx_data)
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
	mlx_close_window(mlx_data.mlx);
}
