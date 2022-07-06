/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:40:14 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/23 12:40:17 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{
	t_data	data;
	void	*img;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 300, "first window");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (0);
	}
	data.img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	img = mlx_xpm_file_to_image(data.mlx_ptr, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}