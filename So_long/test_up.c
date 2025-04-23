/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:34:21 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/03 10:46:02 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test_up(t_data *data)
{
	if (data->copy[data->way.y - 1][data->way.x] == 'C')
		data->way.c++;
	if (data->copy[data->way.y - 1][data->way.x] == 'E')
		data->way.e++;
	if (data->way.c == data->item && data->way.e == 1)
		return ;
	if (data->copy[data->way.y][data->way.x] != 'P')
		data->copy[data->way.y][data->way.x] = 'i';
	new_move(data, 'u');
	data->way.y--;
}
