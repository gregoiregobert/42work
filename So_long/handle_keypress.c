/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:56:44 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/23 15:58:17 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_w)
		dir_up(data);
	if (keysym == XK_s)
		dir_down(data);
	if (keysym == XK_d)
		dir_right(data);
	if (keysym == XK_a)
		dir_left(data);
	if (keysym == XK_Escape)
			exit_properly(data);
	return (0);
}