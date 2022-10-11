/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:24:19 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/11 16:58:19 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	write_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	printf("%ld %d died, %ld ms ago\n", get_time(philo->data), philo->data->death, get_time(philo->data) - philo->last_meal - philo->data->die);
	pthread_mutex_unlock(&philo->data->write);
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
	pthread_mutex_unlock(&philo->data->dead);
	if (philo->data->death > -1)
		return (1);
	return (0);
}
