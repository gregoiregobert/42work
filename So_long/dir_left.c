/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:06:28 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/22 14:14:58 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dir_left(t_data *data)
{	
	if (data->map[data->perso.y][data->perso.x - 1] == '1')
	{
		dir_wall_left(data);
		return ;
	}
	else if (data->map[data->perso.y][data->perso.x - 1] == 'E')
	{
		if (no_c(data) == 0)
			exit_properly(data);
		data->map[data->perso.y][data->perso.x - 1] = 'S';
	}
	else if (data->map[data->perso.y][data->perso.x - 1] == 'C')
		data->map[data->perso.y][data->perso.x - 1] = 'Y';
	else
		data->map[data->perso.y][data->perso.x - 1] = 'Q';
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

void	dir_wall_left(t_data *data)
{
	if (data->map[data->perso.y][data->perso.x] == 'U'
		|| data->map[data->perso.y][data->perso.x] == 'S'
		|| data->map[data->perso.y][data->perso.x] == 'D'
		|| data->map[data->perso.y][data->perso.x] == 'F')
	{
		data->map[data->perso.y][data->perso.x] = 'S';
		display_map(data);
	}
	else
	{
		data->map[data->perso.y][data->perso.x] = 'Q';
		display_map(data);
	}
}
