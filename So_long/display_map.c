/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:10:10 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/21 13:22:02 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_data *data)
{
	int		i;
	int		j;
	char	*move;

	j = -1;
	while (data->map[++j])
	{
		i = -1;
		while (data->map[j][++i])
			display_tile(data, j, i);
	}
	move = ft_itoa(data->move);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 28, 33, 0x00, move);
	free(move);
}
