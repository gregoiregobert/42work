/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:17:32 by gregoiregob       #+#    #+#             */
/*   Updated: 2022/10/01 16:16:03 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_way(t_data *data)
{
	int	i;

	find_p(data);
	map_copy(data);
	data->way.C = 0;
	data->way.E = 0;
	data->way.move = 0;
	data->way.x = data->perso.x;
	data->way.y = data->perso.y;
	while (data->way.C != data->item || data->way.E != 1)
	{
		i = -1;
		printf("\nmove = %d\n", data->way.move);
		while (data->copy[++i])
			printf("%s\n", data->copy[i]);
		printf("\n");
		if (data->copy[data->way.y][data->way.x + 1] != '1'
			&& data->copy[data->way.y][data->way.x + 1] != 'i')
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
		{
			if (data->copy[data->way.y][data->way.x] != 'P')
				data->copy[data->way.y][data->way.x] = '1'; 
			if (data->copy[data->way.y][data->way.x] == 'P')
				return (0);
			else if ((data->way.move - 1) % 10 == 0)
				data->way.x--;
			else if ((data->way.move - 2) % 10 == 0)
				data->way.y--;
			else if ((data->way.move - 3) % 10 == 0)
				data->way.x++;
			else if ((data->way.move - 4) % 10 == 0)
				data->way.y++;
			data->way.move /= 10;
		}
	}
	printf("c = %d\nE = %d\n", data->way.C, data->way.E);
	return(1);
}

void    map_copy(t_data *data)
{
	int i;

	i = -1;
	data->copy = malloc(sizeof(char *) * (data->height_window + 1));
	if (!data->copy)
		return;
	while (data->map[++i])
		data->copy[i] = ft_strdup(data->map[i]);
	data->copy[i] = 0;
}

void    find_p(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (data->map[++i])
	{
			j = -1;
			while (data->map[i][++j])
			{
				if (data->map[i][j] == 'P')
				{
					position_perso(data, i, j);
					return;
				}
			}
	}
}