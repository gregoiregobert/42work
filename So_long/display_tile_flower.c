/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile_flower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:47:50 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/18 15:47:54 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_tile_flower(t_data *data, int j, int i)
{
	if (data->map[j][i] == 'O')
	{
		data->perso.x = i;
		data->perso.y = j;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_flower.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'Y')
	{
		data->perso.x = i;
		data->perso.y = j;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_flower_l.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'A')
	{
		data->perso.x = i;
		data->perso.y = j;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_flower_d.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'I')
	{
		data->perso.x = i;
		data->perso.y = j;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->bee_flower_r.img, 60 * i, 60 * j);
	}
}