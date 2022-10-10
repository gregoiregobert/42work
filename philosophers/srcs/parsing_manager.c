/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:32:38 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/10 10:54:15 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	parsing_manager(t_data *data, int ac, char **av)
{
	if (gettimeofday(&data->start, 0) == -1)
		return (-1);
	if (checks_args(ac, av) == -1)
		return (-1);
	parsing(data, ac, av);
	if (check_value(data, ac) == -1)
		return (-1);
	return (0);
}

int	checks_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		write(2, ERR_ARGS, ft_strlen(ERR_ARGS));
		return (-1);
	}
	while (av[++i])
	{
		if (str_isdigit(av[i]) == 0)
		{
			write(2, ERR_ARGTYPE, ft_strlen(ERR_ARGTYPE));
			return (-1);
		}
	}
	return (0);
}

void	parsing(t_data *data, int ac, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->many_meal = ft_atoi(av[5])
}

int	check_value(t_data *data, int ac)
{
	if (data->nb_philo < 2)
	{
		write(2, ERR_NBPHILO, ft_strlen(ERR_NBPHILO));
		return (-1);
	}
	if (data->die < 0 || data->eat < 0 || data->sleep < 0)
	{
		write(2, ERR_NEG, ft_strlen(ERR_NEG));
		return (-1);
	}
	if (ac == 6)
		if (data->many_meal < 1)
		{
			write(2, ERR_NEG, ft_strlen(ERR_NEG));
			return (-1);
		}
	return (0);
}
