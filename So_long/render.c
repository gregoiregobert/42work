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
	/*render_background(data, 0xFFFFFF);*/
	data->test.img = mlx_xpm_file_to_image(data->mlx_ptr, "./Texture/Food.xpm", &data->test.bpp, &data->test.line_len);
	data->test.addr = mlx_get_data_addr(data->test.img, &data->test.bpp, &data->test.line_len, &data->test.endian);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->test.img, 0, 0);

	return (0);
}