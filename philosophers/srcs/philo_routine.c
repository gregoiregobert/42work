/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:54 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/10 17:36:17 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	routine(t_philo	*philo)
{
		pthread_mutex_lock(&philo->data->fork[philo->index]);
		if (check_death(philo) != 0)
			return (1);
		write_fork(philo);
		pthread_mutex_lock(&philo->data->fork[philo->index + 1]);
		philo->last_meal = get_time(philo->data);
		if (check_death(philo) != 0)
			return (1);
		write_fork(philo);
		write_eat(philo);
		usleep(philo->data->eat * 1000);
		pthread_mutex_unlock(&philo->data->fork[philo->index]);
		pthread_mutex_unlock(&philo->data->fork[philo->index + 1]);
		if (check_death(philo) != 0)
			return (1);
		write_sleep(philo);
		usleep(philo->data->sleep * 1000);
		if (check_death(philo) != 0)
			return (1);
		write_think(philo);
		return (0);
}

void	write_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%ld %d has taken a fork\n", get_time(philo->data), philo->index);
	pthread_mutex_unlock(&philo->data->write);
}

void	write_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%ld %d is eating\n", get_time(philo->data), philo->index);
	pthread_mutex_unlock(&philo->data->write);
}

void	write_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%ld %d is sleeping\n", get_time(philo->data), philo->index);
	pthread_mutex_unlock(&philo->data->write);
}

void	write_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%ld %d is thinking\n", get_time(philo->data), philo->index);
	pthread_mutex_unlock(&philo->data->write);
}