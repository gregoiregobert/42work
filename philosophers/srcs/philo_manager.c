/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:17:48 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/11 11:54:19 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	philo_manager(t_data *data)
{
	int	i;

	i = -1;
	if (init_philo(data) == -1)
		return (-1);
	while (++i < data->nb_philo)
	{
		if (pthread_join(data->philo[i]->th, NULL) != 0)
		{
			write(2, ERR_THJOIN, ft_strlen(ERR_THJOIN));
			return (-1);
		}
	}
	return (0);
}

void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->index == philo->data->nb_philo - 1)
		{
			if (routine_last_philo(philo) != 0)
				return (0);
		}
		else
			if (routine(philo) != 0)
				return (0);
	}
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		usleep(20);
		data->philo[i]->index = i;
		if (pthread_create(&data->philo[i]->th, 0, &philosopher,
				(void *)data->philo[i]) != 0)
		{
			write(2, ERR_PTHR, ft_strlen(ERR_PTHR));
			return (0);
		}
	}
	return (0);
}
