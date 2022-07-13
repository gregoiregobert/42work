/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:09:44 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/13 15:09:46 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_direction(int keysym, t_data *data)
{
	if (keysym == XK_w)
	{
		if (data->map[data->perso.y - 1][data->perso.x] == '1')
			return (0);		
		else if (data->map[data->perso.y - 1][data->perso.x] == 'E')
			data->map[data->perso.y - 1][data->perso.x] = 'U';
		else if (data->map[data->perso.y - 1][data->perso.x] == 'C')
			data->map[data->perso.y - 1][data->perso.x] = 'O';
		else
			data->map[data->perso.y - 1][data->perso.x] = 'P';

		if (data->map[data->perso.y][data->perso.x] == 'U')
			data->map[data->perso.y][data->perso.x] = 'E';
		else
			data->map[data->perso.y][data->perso.x] = '0';

		display_map(data);
	}
	if (keysym == XK_s)
	{
		if (data->map[data->perso.y + 1][data->perso.x] == '1')
			return (0);		
		else if (data->map[data->perso.y + 1][data->perso.x] == 'E')
			data->map[data->perso.y + 1][data->perso.x] = 'U';
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
	if (keysym == XK_d)
	{
		if (data->map[data->perso.y][data->perso.x + 1] == '1')
			return (0);		
		else if (data->map[data->perso.y][data->perso.x + 1] == 'E')
			data->map[data->perso.y][data->perso.x + 1] = 'U';
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
	if (keysym == XK_a)
	{
		if (data->map[data->perso.y][data->perso.x - 1] == '1')
			return (0);		
		else if (data->map[data->perso.y][data->perso.x - 1] == 'E')
			data->map[data->perso.y][data->perso.x - 1] = 'U';
		else if (data->map[data->perso.y][data->perso.x - 1] == 'C')
			data->map[data->perso.y][data->perso.x - 1] = 'O';
		else
			data->map[data->perso.y][data->perso.x - 1] = 'P';

		if (data->map[data->perso.y][data->perso.x] == 'U')
			data->map[data->perso.y][data->perso.x] = 'E';
		else
			data->map[data->perso.y][data->perso.x] = '0';

		display_map(data);
	}
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
