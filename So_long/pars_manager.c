/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:46:41 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/12 14:46:43 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pars_manager(char **av, t_data *data)
{
	dimension_rect(av, data);
	parsing(av, data);
	if	(symbole_check(data) == 1)
		msg_err_1();
	if (wall_check(data) == 1)
		msg_err_2();
	if (rect_check(data) == 1)
		msg_err_3();
	if (item_position_out_check(data) == 1)
		msg_err_4();
}
