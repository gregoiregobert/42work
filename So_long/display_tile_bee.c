/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile_bee.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:01:10 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/19 14:12:27 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_tile_bee(t_data *data, int j, int i)
{
	if (data->map[j][i] == 'P')
	{
		position_perso(data, j, i);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'Q')
	{
		position_perso(data, j, i);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_l.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'R')
	{
		position_perso(data, j, i);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_d.img, 60 * i, 60 * j);
	}
	if (data->map[j][i] == 'W')
	{
		position_perso(data, j, i);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->bee_r.img, 60 * i, 60 * j);
	}
}
