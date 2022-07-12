/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_position_out_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:13:27 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/09 18:13:29 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	item_position_out_check(t_data *data)
{
	int	i;
	int	j;
	int	item;
	int	position;
	int	out;

	j = -1;
	item = 0;
	position = 0;
	out = 0;
	while (data->map[++j])
	{
		i = -1;
		while (data-map[j][++i])
		{
			if (data-map[j][i] == 'C')
				item++;
			if (data-map[j][i] == 'E')
				out++;
			if (data-map[j][i] == 'P')
				position++;
		}
	}
	if (out != 1 || position != 1 || item < 1)
		return (1);
	return (0);
}
