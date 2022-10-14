/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:29:00 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/14 15:03:51 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	routine_last_philo(t_philo	*philo)
{	
	if (one_philo(philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->data->fork[philo->index]);
	if (any_death(philo, philo->index, -1) != 0)
		return (1);
	write_fork(philo);
	pthread_mutex_lock(&philo->data->fork[0]);
	if (any_death(philo, philo->index, 0) != 0)
		return (1);
	write_fork(philo);
	write_eat(philo);
	last_meal(philo);
	usleep(philo->data->eat * 1000);
	pthread_mutex_unlock(&philo->data->fork[philo->index]);
	pthread_mutex_unlock(&philo->data->fork[0]);
	if (any_death(philo, -1, -1) != 0)
		return (1);
	write_sleep(philo);
	usleep(philo->data->sleep * 1000);
	if (any_death(philo, -1, -1) != 0)
		return (1);
	write_think(philo);
	return (0);
}

void	last_meal(t_philo *philo)
{
	philo->many_meal++;
	if (philo->many_meal == philo->data->many_meal)
	{
		pthread_mutex_lock(&philo->data->meal);
		philo->data->meal_control++;
		pthread_mutex_unlock(&philo->data->meal);
	}
	pthread_mutex_lock(&philo->data->dead);
	philo->last_meal = get_time(philo->data);
	pthread_mutex_unlock(&philo->data->dead);
}

int	one_philo(t_philo *philo)
{
	if (philo->data->nb_philo != 1)
		return (0);
	write_fork(philo);
	usleep(philo->data->die * 1000 + 1000);
	return (1);
}

void	write_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%ld	%d is thinking\n", get_time(philo->data), philo->index + 1);
	pthread_mutex_unlock(&philo->data->write);
}
