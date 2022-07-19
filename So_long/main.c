/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:40:14 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/19 14:29:41 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	pars_manager(ac, av, &data);
	initialize(&data);
	map_manager(&data);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 50, 0x00, "hello");
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, &handle_cross, &data);
	mlx_loop(data.mlx_ptr);
	exit_properly(&data);
}
