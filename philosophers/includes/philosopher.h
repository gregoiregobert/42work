/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:00:02 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/07 13:16:10 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define ERR_ARGS "wrong number of arguments\n"
# define ERR_ARGTYPE "arguments must be numeric\n"

typedef struct s_data
{
	int	nb_philo;
	int	die;
	int	eat;
	int	sleep;
	int many_meal;
}	t_data;

#endif