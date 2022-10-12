/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:24:19 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/12 15:43:32 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	write_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%ld %d died, %ld ms ago\n", get_time(philo->data), philo->data->death, get_time(philo->data) - philo->last_meal - philo->data->die);
	pthread_mutex_unlock(&philo->data->write);
}

int	any_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead);
	if (philo->data->death > -1)
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
	if (get_time(philo->data) - philo->last_meal > philo->data->die
		&& philo->data->death < 0)
	{
		philo->data->death = philo->index;
		pthread_mutex_unlock(&philo->data->dead);
		write_dead(philo);
		return (1);
	}
	if (philo->data->death > -1)
	{
		pthread_mutex_unlock(&philo->data->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (0);
}

int	anticipate_death(t_philo *philo, int action)
{
	if (get_time(philo->data) - philo->last_meal + action > philo->data->die)
	{
		usleep((philo->data->die - (get_time(philo->data) - philo->last_meal)) * 1000);
		pthread_mutex_lock(&philo->data->dead);
		if (philo->data->death > -1)
		{
			pthread_mutex_unlock(&philo->data->dead);
			return (1);
		}
		philo->data->death = philo->index;
		pthread_mutex_unlock(&philo->data->dead);
		write_dead(philo);
		return (1);
	}
	return (0);
}