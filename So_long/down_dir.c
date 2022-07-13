/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:17:40 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/13 16:17:42 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	down_dir(t_data *data)
{
	if (data->map[data->perso.y + 1][data->perso.x] == '1')
		return;		
	else if (data->map[data->perso.y + 1][data->perso.x] == 'E')
	{
		if (no_c(data) == 0)
			exit_properly(data);
		data->map[data->perso.y + 1][data->perso.x] = 'U';
	}
	else if (data->map[data->perso.y + 1][data->perso.x] == 'C')
		data->map[data->perso.y + 1][data->perso.x] = 'O';
	else
		data->map[data->perso.y + 1][data->perso.x] = 'P';
	if (data->map[data->perso.y][data->perso.x] == 'U')
		data->map[data->perso.y][data->perso.x] = 'E';
	else
		data->map[data->perso.y][data->perso.x] = '0';
	display_map(data);
}
