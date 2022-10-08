/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:00:02 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/08 18:14:27 by ggobert          ###   ########.fr       */
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

pthread_mutex_t	mutex;

typedef struct s_data
{
	int				nb_philo;
	int				die;
	int				eat;
	int				sleep;
	int				many_meal;
	int				death;
	int				*fork;
	pthread_t		*th;
	struct timeval	sec;
	struct timeval	start;
}	t_data;

void	checks_args(int ac, char **av);
void	check_value(t_data *data, int ac);
void	err_msg_0(void);
void	err_msg_1(void);
void	err_msg_2(void);
void	err_msg_3(void);
void	err_msg_4(void);
void	err_msg_5(void);
void	err_msg_6(void);
long	get_time(t_data *data);
void	init_philo(t_data *data);
void	parsing(t_data *data, int ac, char **av);
void	parsing_manager(t_data *data, int ac, char **av);
void	philo_manager(t_data *data);
void	*philosopher();
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		str_isdigit(char *str);
size_t	ft_strlen(const char *str);
t_data	*init_data(void);

#endif