/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbole_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:23:50 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/09 18:23:55 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so-long.h"

int	symbole_check(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while(data->map[++j])
		while(data->map[j][++i])
			if (data->map[j][i] != 1 || data->map[j][i] != 0
				|| data->map[j][i] != C || data->map[j][i] != E
				||	data->map[j][i] != P)
				return (1);
	return (0);
}
