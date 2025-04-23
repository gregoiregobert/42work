/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:38:30 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/09 17:38:32 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rect_check(t_data *data)
{
	int	i;

	i = -1;
	while (data->map[++i])
		if (strlen(data->map[i]) != data->width_window)
			return (1);
	return (0);
}
