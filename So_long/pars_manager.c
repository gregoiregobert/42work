/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:46:41 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/19 14:37:45 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pars_manager(int ac, char **av, t_data *data)
{
	int	i;

	i = -1;
	data->height_window = 0;
	data->width_window = 0;
	data->move = 0;
	data->item = 0;
	data->position = 0;
	data->out = 0;
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
}
