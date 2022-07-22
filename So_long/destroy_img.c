/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:00:35 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/22 11:30:59 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_data *data)
{
	if (data->grass.img)
		mlx_destroy_image(data->mlx_ptr, data->grass.img);
	if (data->flower.img)
		mlx_destroy_image(data->mlx_ptr, data->flower.img);
	if (data->wall.img)
		mlx_destroy_image(data->mlx_ptr, data->wall.img);
	if (data->hive.img)
		mlx_destroy_image(data->mlx_ptr, data->hive.img);
	if (data->bee.img)
		mlx_destroy_image(data->mlx_ptr, data->bee.img);
	if (data->bee_l.img)
		mlx_destroy_image(data->mlx_ptr, data->bee_l.img);
	if (data->bee_r.img)
		mlx_destroy_image(data->mlx_ptr, data->bee_r.img);
	destroy_img_1(data);
}

void	destroy_img_1(t_data *data)
{
	if (data->bee_d.img)
		mlx_destroy_image(data->mlx_ptr, data->bee_d.img);
	if (data->bee_flower.img)
		mlx_destroy_image(data->mlx_ptr, data->bee_flower.img);
	if (data->bee_flower_r.img)
		mlx_destroy_image(data->mlx_ptr, data->bee_flower_r.img);
	if (data->bee_flower_l.img)
		mlx_destroy_image(data->mlx_ptr, data->bee_flower_l.img);
	if (data->bee_flower_d.img)
		mlx_destroy_image(data->mlx_ptr, data->bee_flower_d.img);
	if (data->bee_hive.img)
		mlx_destroy_image(data->mlx_ptr, data->bee_hive.img);
	if (data->bee_hive_r.img)
		mlx_destroy_image(data->mlx_ptr, data->bee_hive_r.img);
	if (data->bee_hive_l.img)
		mlx_destroy_image(data->mlx_ptr, data->bee_hive_l.img);
	if (data->bee_hive_d.img)
		mlx_destroy_image(data->mlx_ptr, data->bee_hive_d.img);
}
