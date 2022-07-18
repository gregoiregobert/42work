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
		return ;
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
	ft_putnbr_fd(data->move, 1);
	write(1, "\n", 1);
	display_map(data);
}
