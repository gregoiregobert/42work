/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:42:53 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/07 14:58:51 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	err_msg_0(void)
{
	write(2, ERR_ARGS, ft_strlen(ERR_ARGS));
	exit(EXIT_FAILURE);
}

void	err_msg_1(void)
{
	write(2, ERR_ARGTYPE, ft_strlen(ERR_ARGTYPE));
	exit(EXIT_FAILURE);
}

void	err_msg_2(void)
{
	write(2, ERR_MALLOC, ft_strlen(ERR_MALLOC));
	exit(EXIT_FAILURE);
}

void	err_msg_3(void)
{
	write(2, ERR_NBPHILO, ft_strlen(ERR_NBPHILO));
	exit(EXIT_FAILURE);
}

void	err_msg_4(void)
{
	write(2, ERR_NEG, ft_strlen(ERR_NEG));
	exit(EXIT_FAILURE);
}
