/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:05:34 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/22 14:14:51 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dir_down(t_data *data)
{
	if (data->map[data->perso.y + 1][data->perso.x] == '1')
	{
		dir_wall_down(data);
		return ;
	}
	else if (data->map[data->perso.y + 1][data->perso.x] == 'E')
	{
		if (no_c(data) == 0)
			exit_properly(data);
		data->map[data->perso.y + 1][data->perso.x] = 'F';
	}
	else if (data->map[data->perso.y + 1][data->perso.x] == 'C')
		data->map[data->perso.y + 1][data->perso.x] = 'A';
	else
		data->map[data->perso.y + 1][data->perso.x] = 'R';
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

void	dir_wall_down(t_data *data)
{
	if (data->map[data->perso.y][data->perso.x] == 'U'
		|| data->map[data->perso.y][data->perso.x] == 'S'
		|| data->map[data->perso.y][data->perso.x] == 'D'
		|| data->map[data->perso.y][data->perso.x] == 'F')
	{
		data->map[data->perso.y][data->perso.x] = 'F';
		display_map(data);
	}
	else
	{
		data->map[data->perso.y][data->perso.x] = 'R';
		display_map(data);
	}
}
