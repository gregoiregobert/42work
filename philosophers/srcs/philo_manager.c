/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:17:48 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/10 11:40:08 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	philo_manager(t_data *data)
{
	int	i;

	i = 0;
	init_philo(data);
	while (i > data->nb_philo)
		if (!pthread_join(data->th[i], NULL))
		{
			write(2, ERR_THJOIN, ft_strlen(ERR_THJOIN));
			return (-1);
		}
	return (0);
}

void	*philosopher(void *test)
{
	t_data	*data;
	
	data = (t_data*)test;
	while (death != 1)
	{
		pthread_mutex_lock(&mutex);
		if ()
	}
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&mutex, 0);
	data->th = malloc(sizeof(unsigned long) * data->nb_philo);
	if (!data->th)
	{
		write(2, ERR_MALLOC, ft_strlen(ERR_MALLOC));
		return (-1);
	}
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i++].th, 0, &philosopher, data) != 0)
		{
			write(2, ERR_PTHR, ft_strlen(ERR_PTHR));
			return (-1);
		}
	}
}
