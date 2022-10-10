/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:24:19 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/10 17:34:38 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	am_i_dead(t_philo *philo)
{
	if (get_time(philo->data) - philo->last_meal > philo->data->die && philo->data->death == 0)
	{
		philo->data->death = 1;
		write_dead(philo);
	}
}

void	write_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%ld %d died\n", get_time(philo->data), philo->index);
	pthread_mutex_unlock(&philo->data->write);
}

int	any_victime(t_philo *philo)
{
	if (philo->data->death != 0)
	{
		return (1);
	}	
	pthread_mutex_unlock(&philo->data->dead);
	return (0);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead);
	am_i_dead(philo);
	if (any_victime(philo) != 0)
	{
		pthread_mutex_unlock(&philo->data->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (0);
}
