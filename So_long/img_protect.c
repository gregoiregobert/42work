/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_protect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:08:58 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/22 11:55:34 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_protect(t_data *data)
{
	if (!data->grass.img || !data->flower.img || !data->bee.img
		|| !data->bee_r.img || !data->bee_l.img || !data->bee_d.img
		|| !data->wall.img || !data->hive.img || !data->bee_flower.img
		|| !data->bee_flower_r.img || !data->bee_flower_l.img
		|| !data->bee_flower_d.img || !data->bee_hive.img
		|| !data->bee_hive_r.img || !data->bee_hive_l.img
		|| !data->bee_hive_d.img)
		msg_err_7(data);
}
