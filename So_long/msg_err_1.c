/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_err_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:00:29 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/21 15:32:45 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	msg_err_5(void)
{
	write(2, "Need symbole in .ber", 21);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	msg_err_6(void)
{
	write(2, "Only 1 arg allowed", 19);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	msg_err_7(t_data *data)
{
	write(2, "Img not found", 14);
	write(2, "\n", 1);
	exit_properly(data);
	exit(EXIT_FAILURE);
}
