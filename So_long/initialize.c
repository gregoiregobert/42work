/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:18:15 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/07 16:18:17 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		perror(strerror(errno));
		exit(EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width_window, data->height_window, "so_long");
	if (!data->win_ptr)
	{
		free(data->win_ptr);
		perror(strerror(errno));
		exit(EXIT_FAILURE);
	}
	data->height_window = 0;
	data->width_window = 0;
}