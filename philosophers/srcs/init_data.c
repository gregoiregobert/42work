/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:11:14 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/14 14:17:32 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_data	*init_data(char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		write(2, ERR_MALLOC, ft_strlen(ERR_MALLOC));
		return (0);
	}
	if (init_fork(data, av) == -1)
		return (0);
	if (alloc_philo(data, av) == -1)
		return (0);
	pthread_mutex_init(&data->dead, 0);
	pthread_mutex_init(&data->write, 0);
	pthread_mutex_init(&data->meal, 0);
	return (data);
}

int	alloc_philo(t_data *data, char **av)
{
	int	i;

	i = -1;
	data->philo = malloc(sizeof(t_philo *) * (ft_atoi(av[1]) + 1));
	if (!data->philo)
	{
		while (++i < ft_atoi(av[1]) + 1)
			free(data->fork++);
		write(2, ERR_MALLOC, ft_strlen(ERR_MALLOC));
		return (-1);
	}
	while (++i < ft_atoi(av[1]) + 1)
	{
		data->philo[i] = malloc(sizeof(t_philo));
		if (!data->philo[i])
		{
			while (*data->philo)
				free(*data->philo++);
			free(data->philo);
			free(data);
			return (-1);
		}
		init_val(data, i);
	}
	return (0);
}

void	init_val(t_data *data, int i)
{
	data->philo[i]->data = data;
	data->philo[i]->last_meal = 0;
}

int	init_fork(t_data *data, char **av)
{
	int	i;

	i = -1;
	data->fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	if (!data->fork)
	{
		free(data);
		write(2, ERR_MALLOC, ft_strlen(ERR_MALLOC));
		return (-1);
	}
	while (++i < ft_atoi(av[1]))
	{
		if (pthread_mutex_init(&data->fork[i], 0) != 0)
		{
			free(data->fork);
			free(data);
			write(2, ERR_MUTEX, ft_strlen(ERR_MUTEX));
			return (-1);
		}		
	}
	return (0);
}
