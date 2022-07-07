/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_no_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:38:57 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/23 16:39:01 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_data *data)
{

	if (!data->win_ptr)
		return (1);
	
	data->space.img = mlx_xpm_file_to_image(data->mlx_ptr, "./Texture/space.xpm", &data->space.bpp, &data->space.line_len);
	data->space.addr = mlx_get_data_addr(data->space.img, &data->space.bpp, &data->space.line_len, &data->space.endian);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->space.img, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->space.img, 1024, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->space.img, 0, 1024);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->space.img, 1024, 1024);

	data->ship.img = mlx_xpm_file_to_image(data->mlx_ptr, "./Texture/titan.xpm", &data->ship.bpp, &data->ship.line_len);
	data->ship.addr = mlx_get_data_addr(data->ship.img, &data->ship.bpp, &data->ship.line_len, &data->ship.endian);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ship.img, 0, 0);

	return (0);
}