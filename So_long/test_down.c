/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:29:13 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/01 15:53:59 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    test_down(t_data *data)
{
	if (data->copy[data->way.y + 1][data->way.x] == 'C')
		data->way.C++;
	if (data->copy[data->way.y + 1][data->way.x] == 'E')
		data->way.E++;
	if (data->way.C == data->item && data->way.E == 1)
		return;
	if (data->copy[data->way.y][data->way.x] != 'P')
		data->copy[data->way.y][data->way.x] = 'i';
	data->way.move = data->way.move * 10 + 2;
	data->way.y++;
}
