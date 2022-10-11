/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:24:19 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/11 11:29:04 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	write_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%ld %d died\n", get_time(philo->data), philo->data->death);
	pthread_mutex_unlock(&philo->data->write);
}

int	any_victime(t_philo *philo)
{
	if (philo->data->death != 0)
	{
		pthread_mutex_unlock(&philo->data->dead);
		return (1);
	}	
	pthread_mutex_unlock(&philo->data->dead);
	return (0);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead);
	if (get_time(philo->data) - philo->last_meal
		> philo->data->die && philo->data->death == 0)
		philo->data->death = philo->index;
	if (any_victime(philo) != 0 || philo->many_meal == philo->data->many_meal)
	{
		pthread_mutex_unlock(&philo->data->dead);
		if (philo->data->death == philo->index)
			write_dead(philo);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (0);
}
