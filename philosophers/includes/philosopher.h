/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:00:02 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/10 11:40:31 by ggobert          ###   ########.fr       */
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
# define ERR_MALLOC "malloc failed\n"
# define ERR_NBPHILO "2 philosophers minimum\n"
# define ERR_NEG "arguments must be positive value\n"
# define ERR_PTHR "failed to create thread\n"
# define ERR_THJOIN "failed to join thread\n"
# define ERR_TIME "gettimeofday failed\n"

pthread_mutex_t	mutex;

typedef struct s_philo
{
	int				index;
	pthread_t		th;
	t_data 			*data;	
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				die;
	int				eat;
	int				sleep;
	int				many_meal;
	int				index;
	int				death;
	int				*fork;
	t_philo			**philo;
	struct timeval	sec;
	struct timeval	start;
}	t_data;

void	init_philo(t_data *data);
void	parsing(t_data *data, int ac, char **av);
void	*philosopher();
int		check_value(t_data *data, int ac);
int		checks_args(int ac, char **av);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		get_time(t_data *data);
int		parsing_manager(t_data *data, int ac, char **av);
int		philo_manager(t_data *data);
int		str_isdigit(char *str);
size_t	ft_strlen(const char *str);
t_data	*init_data(void);

#endif