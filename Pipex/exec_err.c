/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:40:25 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/15 11:41:54 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execution_manager(t_cmd *cmd, char **ev, char **av)
{
	int	err;

	err = 0;
	cmd->err = 0;
	if (init_fd(cmd) == 1 || init_pid(cmd) == 1)
		err_init(cmd);
	err = execute_cmd(cmd, ev);
	if (err == 1)
		err_pipe(cmd);
	if (err == 2)
		err_open(cmd, av);
	if (err == 3)
		err_fork(cmd);
}

void	err_init(t_cmd *cmd)
{
	free_fd_pid(cmd);
	perror("An error ocurred with malloc of fd or pid ");
	exit(EXIT_FAILURE);
}

void	err_pipe(t_cmd *cmd)
{
	free_all(cmd);
	perror("An error ocurred with the pipe function ");
	exit(EXIT_FAILURE);
}

void	err_open(t_cmd *cmd, char **av)
{
	free_all(cmd);
	if (cmd->err == 2 || cmd->err == 3)
	{
		write(2, "no such file or directory: ", 27);
		write(2, "\n", 1);
	}
	if (cmd->err == 1 || cmd->err == 3)
	{
		write(2, "no such file or directory: ", 27);
		write(2, av[1], ft_strlen(av[1]));
		write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}

void	err_fork(t_cmd *cmd)
{
	free_all(cmd);
	perror("An error ocurred with the fork function ");
	exit(EXIT_FAILURE);
}
