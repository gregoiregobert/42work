/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile_bee.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:01:10 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/18 16:01:20 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_tile_bee(t_data *data, int j, int i)
{
	if (data->map[j][i] == 'P')
	{
		data->perso.x = i;
		data->perso.y = j;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'Q')
	{
		data->perso.x = i;
		data->perso.y = j;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_l.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'R')
	{
		data->perso.x = i;
		data->perso.y = j;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_d.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'W')
	{
		data->perso.x = i;
		data->perso.y = j;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_r.img, 60 * i, 60 * j);
	}
}
