/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:32:29 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/01 16:52:03 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    test_left(t_data *data)
{
	if (data->copy[data->way.y][data->way.x - 1] == 'C')
		data->way.C++;
	if (data->copy[data->way.y][data->way.x - 1] == 'E')
		data->way.E++;
	if (data->way.C == data->item && data->way.E == 1)
		return;
	if (data->copy[data->way.y][data->way.x] != 'P')
		data->copy[data->way.y][data->way.x] = 'i';
	new_move(data, 'l');
	data->way.x--;
}
