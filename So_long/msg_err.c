/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:21:04 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/12 15:21:27 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	msg_err_1(t_data *data)
{
	write(2, "Symbole not allowed", 20);
	write(2, '\n', 1);
	free_map(data);
	exit(EXIT_FAILURE);
}

void	msg_err_2(t_data *data)
{
	write(2, "Map have to be surround by wall", 32);
	write(2, '\n', 1);
	free_map(data);
	exit(EXIT_FAILURE);
}

void	msg_err_3(t_data *data)
{
	write(2, "Map has to be a rectangle", 26);
	write(2, '\n', 1);
	free_map(data);
	exit(EXIT_FAILURE);
}

void	msg_err_4(t_data *data)
{
	write(2, "wrong number of item, exit or character", 40);
	write(2, '\n', 1);
	free_map(data);
	exit(EXIT_FAILURE);
}
