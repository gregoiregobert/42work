/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:28:33 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/03 10:46:20 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test_right(t_data *data)
{
	if (data->copy[data->way.y][data->way.x + 1] == 'C')
		data->way.c++;
	if (data->copy[data->way.y][data->way.x + 1] == 'E')
		data->way.e++;
	if (data->way.c == data->item && data->way.e == 1)
		return ;
	if (data->copy[data->way.y][data->way.x] != 'P')
		data->copy[data->way.y][data->way.x] = 'i';
	new_move(data, 'r');
	data->way.x++;
}
