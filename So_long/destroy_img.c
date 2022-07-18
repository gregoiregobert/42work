/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:00:35 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/13 17:00:37 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->grass.img);
	mlx_destroy_image(data->mlx_ptr, data->flower.img);
	mlx_destroy_image(data->mlx_ptr, data->wall.img);
	mlx_destroy_image(data->mlx_ptr, data->hive.img);
	mlx_destroy_image(data->mlx_ptr, data->bee.img);
	mlx_destroy_image(data->mlx_ptr, data->bee_l.img);
	mlx_destroy_image(data->mlx_ptr, data->bee_r.img);
	mlx_destroy_image(data->mlx_ptr, data->bee_d.img);
	mlx_destroy_image(data->mlx_ptr, data->bee_flower.img);
	mlx_destroy_image(data->mlx_ptr, data->bee_flower_r.img);
	mlx_destroy_image(data->mlx_ptr, data->bee_flower_l.img);
	mlx_destroy_image(data->mlx_ptr, data->bee_flower_d.img);
	mlx_destroy_image(data->mlx_ptr, data->bee_hive.img);
	mlx_destroy_image(data->mlx_ptr, data->bee_hive_r.img);
	mlx_destroy_image(data->mlx_ptr, data->bee_hive_l.img);
	mlx_destroy_image(data->mlx_ptr, data->bee_hive_d.img);
}
