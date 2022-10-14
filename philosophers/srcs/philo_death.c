/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:24:19 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/14 17:57:24 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	death_control(t_philo *philo)
{
	int	i;

	while (1)
	{
		usleep(1000);
		i = -1;
		while (++i < philo->data->nb_philo)
			if (control_time(philo, i) == 1)
				return (1);
		pthread_mutex_lock(&philo->data->dead);
		if (philo->data->death == -2)
			return (0);
		pthread_mutex_unlock(&philo->data->dead);
	}
	return (0);
}

int	control_time(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->data->dead);
	if (get_time(philo->data) - philo->data->philo[i]->last_meal
		> philo->data->die && philo->data->death == -1)
	{
		philo->data->death = philo->data->philo[i]->index + 1;
		pthread_mutex_unlock(&philo->data->dead);
		write_dead(philo);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead);
	pthread_mutex_lock(&philo->data->meal);
	if (philo->data->meal_control == philo->data->nb_philo)
		philo->data->death = 0;
	pthread_mutex_unlock(&philo->data->meal);
	return (0);
}

int	any_death(t_philo *philo, int index, int index2)
{
	pthread_mutex_lock(&philo->data->dead);
	if (philo->data->death > -1)
	{
		pthread_mutex_unlock(&philo->data->dead);
		if (index != -1)
			pthread_mutex_unlock(&philo->data->fork[index]);
		if (index2 != -1)
			pthread_mutex_unlock(&philo->data->fork[index2]);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (0);
}

void	write_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%ld	%d died\n", get_time(philo->data), philo->data->death);
	pthread_mutex_unlock(&philo->data->write);
}
