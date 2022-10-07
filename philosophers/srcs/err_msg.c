/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:42:53 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/07 13:06:22 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	err_msg_0(void)
{
	write(2, ERR_ARGS, ft_strlen(ERR_ARGS));
	exit;
}

void	err_msg_1(void)
{
	write(2, ERR_ARGTYPE, ft_strlen(ERR_ARGTYPE));
	exit;
}
