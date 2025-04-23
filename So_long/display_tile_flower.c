/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile_flower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:47:50 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/19 14:13:32 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_tile_flower(t_data *data, int j, int i)
{
	if (data->map[j][i] == 'O')
	{
		position_perso(data, j, i);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_flower.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'Y')
	{
		position_perso(data, j, i);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_flower_l.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'A')
	{
		position_perso(data, j, i);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_flower_d.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'I')
	{
		position_perso(data, j, i);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_flower_r.img, 60 * i, 60 * j);
	}
}
