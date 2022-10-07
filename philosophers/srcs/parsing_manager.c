/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:32:38 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/07 13:15:45 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	parsing_manager(t_data *data, int ac, char **av)
{
	checks_args(ac, av);
	parsing(ac, av);
}

void	checks_args(int ac, char **av)
{
	int i;

	i = 0;
	if (ac < 5 || ac > 6)
		err_msg_0();
	while (av[++i])
	{
		if (is_digit(av[i]) == 0)
			err_msg_1;
	}
}

void	parsing(int ac, char **av)
{
	
}