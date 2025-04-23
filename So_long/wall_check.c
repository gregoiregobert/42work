/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:44:29 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/19 14:35:36 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j][i])
		if (data->map[j][i++] != '1')
			return (1);
	while (++j < data->height_window - 1)
		if (data->map[j][0] != '1' ||
			data->map[j][data->width_window - 1] != '1')
			return (1);
	i = 0;
	while (data->map[j][i])
		if (data->map[j][i++] != '1')
			return (1);
	return (0);
}
