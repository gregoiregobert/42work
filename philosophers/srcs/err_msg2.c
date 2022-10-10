/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:13:54 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/10 10:50:37 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	err_msg_5(void)
{
	write(2, ERR_PTHR, ft_strlen(ERR_PTHR));
}

void	err_msg_6(void)
{
	write(2, ERR_THJOIN, ft_strlen(ERR_THJOIN));
}
