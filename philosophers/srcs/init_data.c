/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:11:14 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/08 18:16:54 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		err_msg_2();
	data->fork = malloc(sizeof(int) * data->nb_philo);
	if (data->fork)
		err_msg_2();
	return (data);
}
