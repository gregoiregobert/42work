/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:11:14 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/10 11:12:11 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_data	*init_data(char **av)
{
	t_data	*data;
	t_philo	*philo;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		write(2, ERR_MALLOC, ft_strlen(ERR_MALLOC));
		return (0);
	}
	data->fork = malloc(sizeof(int) * av[1]);
	if (!data->fork)
	{
		free(data);
		write(2, ERR_MALLOC, ft_strlen(ERR_MALLOC));
		return (0);
	}
	if (alloc_philo(data, av) == -1)
		return (0);
	return (data);
}

int	alloc_philo(t_data *data, char **av)
{
	data->philo = malloc(sizeof(t_philo) * av[1]);
	if (!philo)
	{
		while (data->fork)
		write(2, ERR_MALLOC, ft_strlen(ERR_MALLOC));
		return (-1);
	}
}