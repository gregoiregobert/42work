/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:32:38 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/07 15:07:30 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	parsing_manager(t_data *data, int ac, char **av)
{
	checks_args(ac, av);
	parsing(data, ac, av);
	check_value(data, ac);
}

void	checks_args(int ac, char **av)
{
	int i;

	i = 0;
	if (ac < 5 || ac > 6)
		err_msg_0();
	while (av[++i])
		if (str_isdigit(av[i]) == 0)
			err_msg_1();
}

void	parsing(t_data *data, int ac, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->many_meal = ft_atoi(av[5]);
}

void	check_value(t_data *data, int ac)
{
	if (data->nb_philo < 2)
		err_msg_3();
	if (data->die < 0 || data->eat < 0 || data->sleep < 0)
		err_msg_4();
	if (ac == 6)
		if (data->many_meal < 1)
			err_msg_4();
}