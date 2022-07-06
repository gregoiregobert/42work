/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_no_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:38:57 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/23 16:39:01 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	render_background(data, 0xFFFFFF);
	render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, 0xFF00});
	render_rect(data, (t_rect){0, 0, 100, 100, 0xFF});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);

	return (0);
}