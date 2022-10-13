/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:22:59 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/13 16:15:57 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_all(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&data->dead);
	data->death = -2;
	pthread_mutex_unlock(&data->dead);
	while (++i < data->nb_philo + 1)
		free(data->philo[i]);
	free(data->philo);
	free(data->fork);
	free(data);
}
