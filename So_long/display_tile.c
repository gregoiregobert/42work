/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:20:53 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/13 14:20:56 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_tile(t_data *data, int j, int i)
{
	if (data->map[j][i] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->grass.img, 60 * i, 60 * j);
	if (data->map[j][i] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall.img, 60 * i, 60 * j);
	if (data->map[j][i] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->flower.img, 60 * i, 60 * j);
	if (data->map[j][i] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->hive.img, 60 * i, 60 * j);
	if (data->map[j][i] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bee.img, 60 * i, 60 * j);
}