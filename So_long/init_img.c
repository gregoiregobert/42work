/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:13:45 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/22 11:56:19 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_data *data)
{
	data->grass.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/grass.xpm", &data->grass.bpp, &data->grass.line_len);
	data->hive.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/hive.xpm", &data->hive.bpp, &data->hive.line_len);
	data->flower.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/flower.xpm", &data->flower.bpp, &data->flower.line_len);
	data->wall.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/wall.xpm", &data->wall.bpp, &data->wall.line_len);
	data->bee.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/bee.xpm", &data->bee.bpp, &data->bee.line_len);
	data->bee_r.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/bee_right.xpm", &data->bee_r.bpp, &data->bee_r.line_len);
	data->bee_l.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/bee_left.xpm", &data->bee_l.bpp, &data->bee_l.line_len);
	data->bee_d.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/bee_down.xpm", &data->bee_d.bpp, &data->bee_d.line_len);
	init_img_1(data);
}

void	init_img_1(t_data *data)
{
	data->bee_flower.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/bee-flower.xpm", &data->bee_flower.bpp,
			&data->bee_flower.line_len);
	data->bee_flower_r.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/bee-flower_right.xpm",
			&data->bee_flower_r.bpp, &data->bee_flower_r.line_len);
	data->bee_flower_l.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/bee-flower_left.xpm",
			&data->bee_flower_l.bpp, &data->bee_flower_l.line_len);
	data->bee_flower_d.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/bee-flower_down.xpm",
			&data->bee_flower_d.bpp, &data->bee_flower_d.line_len);
	data->bee_hive.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/bee-hive.xpm", &data->bee_hive.bpp,
			&data->bee_hive.line_len);
	data->bee_hive_r.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/bee-hive_right.xpm", &data->bee_hive_r.bpp,
			&data->bee_hive_r.line_len);
	data->bee_hive_l.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/bee-hive_left.xpm", &data->bee_hive_l.bpp,
			&data->bee_hive_l.line_len);
	init_img_2(data);
}

void	init_img_2(t_data *data)
{
	data->bee_hive_d.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Texture/bee-hive_down.xpm", &data->bee_hive_d.bpp,
			&data->bee_hive_d.line_len);
	img_protect(data);
	data->grass.addr = mlx_get_data_addr(data->grass.img, &data->grass.bpp,
			&data->grass.line_len, &data->grass.endian);
	data->hive.addr = mlx_get_data_addr(data->hive.img, &data->hive.bpp,
			&data->hive.line_len, &data->hive.endian);
	data->flower.addr = mlx_get_data_addr(data->flower.img, &data->flower.bpp,
			&data->flower.line_len, &data->flower.endian);
	data->wall.addr = mlx_get_data_addr(data->wall.img, &data->wall.bpp,
			&data->wall.line_len, &data->wall.endian);
	data->bee.addr = mlx_get_data_addr(data->bee.img, &data->bee.bpp,
			&data->bee.line_len, &data->bee.endian);
	data->bee_r.addr = mlx_get_data_addr(data->bee_r.img, &data->bee_r.bpp,
			&data->bee_r.line_len, &data->bee_r.endian);
	data->bee_l.addr = mlx_get_data_addr(data->bee_l.img, &data->bee_l.bpp,
			&data->bee_l.line_len, &data->bee_l.endian);
	data->bee_d.addr = mlx_get_data_addr(data->bee_d.img, &data->bee_d.bpp,
			&data->bee_d.line_len, &data->bee_d.endian);
	data->bee_flower.addr = mlx_get_data_addr(data->bee_flower.img,
			&data->bee_flower.bpp, &data->bee_flower.line_len,
			&data->bee_flower.endian);
	init_img_3(data);
}

void	init_img_3(t_data *data)
{
	data->bee_flower_r.addr = mlx_get_data_addr(data->bee_flower_r.img,
			&data->bee_flower_r.bpp, &data->bee_flower_r.line_len,
			&data->bee_flower_r.endian);
	data->bee_flower_l.addr = mlx_get_data_addr(data->bee_flower_l.img,
			&data->bee_flower_l.bpp, &data->bee_flower_l.line_len,
			&data->bee_flower_l.endian);
	data->bee_flower_d.addr = mlx_get_data_addr(data->bee_flower_d.img,
			&data->bee_flower_d.bpp, &data->bee_flower_d.line_len,
			&data->bee_flower_d.endian);
	data->bee_hive.addr = mlx_get_data_addr(data->bee_hive.img,
			&data->bee_hive.bpp, &data->bee_hive.line_len,
			&data->bee_hive.endian);
	data->bee_hive_r.addr = mlx_get_data_addr(data->bee_hive_r.img,
			&data->bee_hive_r.bpp, &data->bee_hive_r.line_len,
			&data->bee_hive_r.endian);
	data->bee_hive_l.addr = mlx_get_data_addr(data->bee_hive_l.img,
			&data->bee_hive_l.bpp, &data->bee_hive_l.line_len,
			&data->bee_hive_l.endian);
	data->bee_hive_d.addr = mlx_get_data_addr(data->bee_hive_d.img,
			&data->bee_hive_d.bpp, &data->bee_hive_d.line_len,
			&data->bee_hive_d.endian);
}
