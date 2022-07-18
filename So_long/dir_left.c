/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:06:28 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/18 12:06:32 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dir_left(t_data *data)
{	
	if (data->map[data->perso.y][data->perso.x - 1] == '1')
		return ;
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
	ft_putnbr_fd(data->move, 1);
	write(1, "\n", 1);
	display_map(data);
}
