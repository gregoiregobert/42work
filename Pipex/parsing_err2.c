/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_err2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:18:16 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/22 14:18:29 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	env_null(void)
{
	write(2, "An error occured with env Path", 31);
	write(2, "\n", 2);
	exit(EXIT_FAILURE);
}