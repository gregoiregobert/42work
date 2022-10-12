/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:29:00 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/12 16:04:54 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	routine_last_philo(t_philo	*philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->index]);
	if (write_fork(philo, philo->index) != 0)
		return (1);
	pthread_mutex_lock(&philo->data->fork[0]);
	write_eat(philo);
	philo->last_meal = get_time(philo->data);
	if (write_fork_2(philo, 0, philo->index) == 1)
		return (1);
	usleep(philo->data->eat * 1000);
	pthread_mutex_unlock(&philo->data->fork[philo->index]);
	pthread_mutex_unlock(&philo->data->fork[0]);
	write_sleep(philo);
	if (anticipate_death(philo, philo->data->sleep) != 0 || philo->many_meal == philo->data->many_meal)
		return (1);
	usleep(philo->data->sleep * 1000);
	if (any_death(philo) != 0)
		return (1);
	write_think(philo);
	return (0);
}

void	write_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	if (!any_death(philo))
		printf("%ld	%d is thinking\n", get_time(philo->data), philo->index + 1);
	pthread_mutex_unlock(&philo->data->write);
}
