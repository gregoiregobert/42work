/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:06:11 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/18 12:06:15 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dir_right(t_data *data)
{
	if (data->map[data->perso.y][data->perso.x + 1] == '1')
		return;		
	else if (data->map[data->perso.y][data->perso.x + 1] == 'E')
	{
		if (no_c(data) == 0)
			exit_properly(data);
		data->map[data->perso.y][data->perso.x + 1] = 'U';
	}
	else if (data->map[data->perso.y][data->perso.x + 1] == 'C')
		data->map[data->perso.y][data->perso.x + 1] = 'O';
	else
		data->map[data->perso.y][data->perso.x + 1] = 'P';
	if (data->map[data->perso.y][data->perso.x] == 'U')
		data->map[data->perso.y][data->perso.x] = 'E';
	else
		data->map[data->perso.y][data->perso.x] = '0';
	data->move++;
	printf("%d\n", data->move);
	display_map(data);
}
