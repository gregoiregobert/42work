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
	
	data->grass.img = mlx_xpm_file_to_image(data->mlx_ptr, "./Texture/grass.xpm", &data->grass.bpp, &data->grass.line_len);
	data->grass.addr = mlx_get_data_addr(data->grass.img, &data->grass.bpp, &data->grass.line_len, &data->grass.endian);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->grass.img, 0, 0);

	return (0);
}