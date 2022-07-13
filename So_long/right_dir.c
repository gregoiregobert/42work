/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:18:00 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/13 16:18:03 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_dir(t_data *data)
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
	display_map(data);
}
