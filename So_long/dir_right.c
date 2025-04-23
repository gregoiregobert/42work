/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:06:11 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/22 14:15:02 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dir_right(t_data *data)
{
	if (data->map[data->perso.y][data->perso.x + 1] == '1')
	{
		dir_wall_right(data);
		return ;
	}
	else if (data->map[data->perso.y][data->perso.x + 1] == 'E')
	{
		if (no_c(data) == 0)
			exit_properly(data);
		data->map[data->perso.y][data->perso.x + 1] = 'D';
	}
	else if (data->map[data->perso.y][data->perso.x + 1] == 'C')
		data->map[data->perso.y][data->perso.x + 1] = 'I';
	else
		data->map[data->perso.y][data->perso.x + 1] = 'W';
	if (data->map[data->perso.y][data->perso.x] == 'U'
		|| data->map[data->perso.y][data->perso.x] == 'S'
		|| data->map[data->perso.y][data->perso.x] == 'D'
		|| data->map[data->perso.y][data->perso.x] == 'F')
		data->map[data->perso.y][data->perso.x] = 'E';
	else
		data->map[data->perso.y][data->perso.x] = '0';
	data->move++;
	display_map(data);
}

void	dir_wall_right(t_data *data)
{
	if (data->map[data->perso.y][data->perso.x] == 'U'
		|| data->map[data->perso.y][data->perso.x] == 'S'
		|| data->map[data->perso.y][data->perso.x] == 'D'
		|| data->map[data->perso.y][data->perso.x] == 'F')
	{
		data->map[data->perso.y][data->perso.x] = 'D';
		display_map(data);
	}
	else
	{
		data->map[data->perso.y][data->perso.x] = 'W';
		display_map(data);
	}
}
