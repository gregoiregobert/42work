/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile_hive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:58:40 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/19 14:12:24 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_tile_hive(t_data *data, int j, int i)
{
	if (data->map[j][i] == 'U')
	{
		position_perso(data, j, i);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_hive.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'S')
	{
		position_perso(data, j, i);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_hive_l.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'F')
	{
		position_perso(data, j, i);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_hive_d.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'D')
	{
		position_perso(data, j, i);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_hive_r.img, 60 * i, 60 * j);
	}
}
