/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:46:41 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/03 11:05:49 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pars_manager(int ac, char **av, t_data *data)
{
	data->height_window = 0;
	data->width_window = 0;
	data->move = 0;
	data->item = 0;
	data->position = 0;
	data->out = 0;
	data->way.c = 0;
	data->way.e = 0;
	data->way.move = 0;
	check_args(ac, av);
	dimension_rect(av, data);
	parsing(av, data);
	if (symbole_check(data) == 1)
		msg_err_1(data);
	if (rect_check(data) == 1)
		msg_err_2(data);
	if (wall_check(data) == 1)
		msg_err_3(data);
	if (item_position_out_check(data) == 1)
		msg_err_4(data);
	find_p(data);
	map_copy(data);
	if (find_way(data) == 0)
		msg_err_8(data);
}
