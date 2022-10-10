/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:29:00 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/10 17:36:11 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	routine_last_philo(t_philo	*philo)
{
		pthread_mutex_lock(&philo->data->fork[philo->index]);
		if (check_death(philo) != 0)
			return (1);
		write_fork(philo);
		pthread_mutex_lock(&philo->data->fork[0]);
		philo->last_meal = get_time(philo->data);
		if (check_death(philo) != 0)
			return (1);
		write_fork(philo);
		write_eat(philo);
		usleep(philo->data->eat * 1000);
		pthread_mutex_unlock(&philo->data->fork[philo->index]);
		pthread_mutex_unlock(&philo->data->fork[0]);
		if (check_death(philo) != 0)
			return (1);
		write_sleep(philo);
		usleep(philo->data->sleep * 1000);
		if (check_death(philo) != 0)
			return (1);
		write_think(philo);
		return (0);
}