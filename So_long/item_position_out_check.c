/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_position_out_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:13:27 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/19 14:38:44 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	item_position_out_check(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (data->map[++j])
	{
		i = -1;
		while (data->map[j][++i])
		{
			if (data->map[j][i] == 'C')
				data->item++;
			if (data->map[j][i] == 'E')
				data->out++;
			if (data->map[j][i] == 'P')
				data->position++;
		}
	}
	if (data->out != 1 || data->position != 1 || data->item < 1)
		return (1);
	return (0);
}
