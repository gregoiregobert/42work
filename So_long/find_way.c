/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:17:32 by gregoiregob       #+#    #+#             */
/*   Updated: 2022/10/03 13:44:47 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_way(t_data *data)
{
	int	i;

	data->way.x = data->perso.x;
	data->way.y = data->perso.y;
	while (data->way.c != data->item || data->way.e != 1)
	{
		if (data->copy[data->way.y][data->way.x + 1] != '1'
			&& data->copy[data->way.y][data->way.x + 1] != 'i'
			&& data->copy[data->way.y][data->way.x + 1] != 'P')
			test_right(data);
		else if (data->copy[data->way.y + 1][data->way.x] != '1'
			&& data->copy[data->way.y + 1][data->way.x] != 'i')
			test_down(data);
		else if (data->copy[data->way.y][data->way.x - 1] != '1'
				&& data->copy[data->way.y][data->way.x - 1] != 'i')
			test_left(data);
		else if (data->copy[data->way.y - 1][data->way.x] != '1'
				&& data->copy[data->way.y - 1][data->way.x] != 'i')
			test_up(data);
		else
			if (no_way(data) == 0)
				return (0);
	}
	return (1);
}

int	no_way(t_data *data)
{
	data->copy[data->way.y][data->way.x] = '1';
	if (data->copy[data->way.y][data->way.x + 1] == '1'
		&& data->copy[data->way.y + 1][data->way.x] == '1'
		&& data->copy[data->way.y][data->way.x - 1] == '1'
		&& data->copy[data->way.y - 1][data->way.x] == '1')
		return (0);
	else if (backtrack_move(data) == 'r')
		data->way.x--;
	else if (backtrack_move(data) == 'd')
		data->way.y--;
	else if (backtrack_move(data) == 'l')
		data->way.x++;
	else if (backtrack_move(data) == 'u')
		data->way.y++;
	rm_lastmove(data);
	return (1);
}

void	map_copy(t_data *data)
{
	int	i;

	i = -1;
	data->copy = malloc(sizeof(char *) * (data->height_window + 1));
	if (!data->copy)
		return ;
	while (data->map[++i])
		data->copy[i] = ft_strdup(data->map[i]);
	data->copy[i] = 0;
}

void	find_p(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'P')
			{
				position_perso(data, i, j);
				return ;
			}
		}
	}
}
