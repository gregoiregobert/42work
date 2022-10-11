/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:00:02 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/11 14:47:33 by ggobert          ###   ########.fr       */
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
# define ERR_MUTEX "failed to init mutex\n"
# define ERR_TIME "gettimeofday failed\n"

typedef struct s_philo
{
	int				index;
	int				many_meal;
	long			last_meal;
	pthread_t		th;
	struct s_data	*data;	
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				die;
	int				eat;
	int				sleep;
	int				many_meal;
	int				death;
	pthread_mutex_t	write;
	pthread_mutex_t	*fork;
	pthread_mutex_t	dead;
	t_philo			**philo;
	struct timeval	sec;
	struct timeval	start;
}	t_data;

void	free_all(t_data *data);
void	init_val(t_data *data, int i);
void	parsing(t_data *data, int ac, char **av);
void	philo_manager(t_data *data);
void	write_dead(t_philo *philo);
void	write_eat(t_philo *philo);
void	write_sleep(t_philo *philo);
void	write_think(t_philo *philo);
void	*philosopher(void *arg);
int		alloc_philo(t_data *data, char **av);
int		any_victime(t_philo *philo);
int		check_death(t_philo *philo);
int		check_value(t_data *data, int ac);	
int		checks_args(int ac, char **av);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		init_philo(t_data *data);
int		init_fork(t_data *data, char **av);
int		parsing_manager(t_data *data, int ac, char **av);
int		routine(t_philo	*philo);
int		routine_last_philo(t_philo	*philo);
int		str_isdigit(char *str);
int		write_fork(t_philo *philo, int index);
int		write_fork_2(t_philo *philo, int index, int index_2);
long	get_time(t_data *data);
size_t	ft_strlen(const char *str);
t_data	*init_data(char **av);

#endif