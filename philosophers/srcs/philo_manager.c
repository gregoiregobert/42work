/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:17:48 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/08 18:18:41 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philo_manager(t_data *data)
{
	int	i;

	i = 0;
	init_philo(data);
	while (i > data->nb_philo)
		if (pthread_join(data->th[i], NULL) != 0)
			err_msg_6();
	usleep(200000);
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

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&mutex, 0);
	data->th = malloc(sizeof(unsigned long) * data->nb_philo);
	if (!data->th)
		err_msg_2();
	while (i < data->nb_philo)
		if (pthread_create(&data->th[i++], 0, &philosopher, data) != 0)
			err_msg_5();
}
