/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:54 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/11 14:16:46 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	routine(t_philo	*philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->index]);
	if (write_fork(philo, philo->index) == 1)
		return (1);
	pthread_mutex_lock(&philo->data->fork[philo->index + 1]);
	philo->last_meal = get_time(philo->data);
	if (write_fork_2(philo, philo->index + 1, philo->index) == 1)
		return (1);
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

int	write_fork(t_philo *philo, int index)
{
	if (check_death(philo) != 0)
	{
		pthread_mutex_unlock(&philo->data->fork[index]);
		return (1);
	}
	pthread_mutex_lock(&philo->data->write);
	if (!philo->data->death)
		printf("%ld %d has taken a fork\n", get_time(philo->data), philo->index);
	pthread_mutex_unlock(&philo->data->write);
	return (0);
}

int	write_fork_2(t_philo *philo, int index, int index_2)
{
	if (check_death(philo) != 0)
	{
		pthread_mutex_unlock(&philo->data->fork[index]);
		pthread_mutex_unlock(&philo->data->fork[index_2]);
		return (1);
	}
	pthread_mutex_lock(&philo->data->write);
	if (!philo->data->death)
		printf("%ld %d has taken a fork\n", get_time(philo->data), philo->index);
	pthread_mutex_unlock(&philo->data->write);
	return (0);
}

void	write_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	if (!philo->data->death)
		printf("%ld %d is eating\n", get_time(philo->data), philo->index);
	pthread_mutex_unlock(&philo->data->write);
}

void	write_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	if (!philo->data->death)
		printf("%ld %d is sleeping\n", get_time(philo->data), philo->index);
	pthread_mutex_unlock(&philo->data->write);
	philo->many_meal++;
}
