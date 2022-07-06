/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:31:55 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/06 13:31:58 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_pixel_put(t_data *data, int x, int y, int color)
{
	char    *pixel;

    pixel = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(int *)pixel = color;
}