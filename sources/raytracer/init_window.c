/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_window.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hesmolde <hesmolde@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/17 16:35:07 by hesmolde      #+#    #+#                 */
/*   Updated: 2025/01/28 17:45:05 by hesmolde      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "MINI_RT", false);
	if (!data->mlx)
		exit(1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		mlx_terminate(data->mlx);
		exit(1);
	}
}