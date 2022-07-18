/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile_hive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:58:40 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/18 15:58:42 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_tile_hive(t_data *data, int j, int i)
{
	if (data->map[j][i] == 'U')
	{
		data->perso.x = i;
		data->perso.y = j;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_hive.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'S')
	{
		data->perso.x = i;
		data->perso.y = j;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_hive_l.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'F')
	{
		data->perso.x = i;
		data->perso.y = j;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_hive_d.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'D')
	{
		data->perso.x = i;
		data->perso.y = j;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_hive_r.img, 60 * i, 60 * j);
	}
}

