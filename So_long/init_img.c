/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:13:45 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/13 14:13:46 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_data *data)
{
	data->grass.img = mlx_xpm_file_to_image(data->mlx_ptr, "./Texture/grass.xpm", &data->grass.bpp, &data->grass.line_len);
	data->grass.addr = mlx_get_data_addr(data->grass.img, &data->grass.bpp, &data->grass.line_len, &data->grass.endian);
	data->hive.img = mlx_xpm_file_to_image(data->mlx_ptr, "./Texture/hive.xpm", &data->hive.bpp, &data->hive.line_len);
	data->hive.addr = mlx_get_data_addr(data->hive.img, &data->hive.bpp, &data->hive.line_len, &data->hive.endian);
	data->flower.img = mlx_xpm_file_to_image(data->mlx_ptr, "./Texture/flower.xpm", &data->flower.bpp, &data->flower.line_len);
	data->flower.addr = mlx_get_data_addr(data->flower.img, &data->flower.bpp, &data->flower.line_len, &data->flower.endian);
	data->wall.img = mlx_xpm_file_to_image(data->mlx_ptr, "./Texture/wall.xpm", &data->wall.bpp, &data->wall.line_len);
	data->wall.addr = mlx_get_data_addr(data->wall.img, &data->wall.bpp, &data->wall.line_len, &data->wall.endian);
	data->bee.img = mlx_xpm_file_to_image(data->mlx_ptr, "./Texture/bee.xpm", &data->bee.bpp, &data->bee.line_len);
	data->bee.addr = mlx_get_data_addr(data->bee.img, &data->bee.bpp, &data->bee.line_len, &data->bee.endian);
}
