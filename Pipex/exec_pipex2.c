/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipex2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:37:36 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/14 16:38:01 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_fd(t_cmd *cmd)
{
	int	i;

	i = 0;
	cmd->fd = malloc(sizeof(int *) * cmd->nb_cmd);
	if (!cmd->fd)
		return (1);
	while (i < cmd->nb_cmd)
	{
		cmd->fd[i] = malloc(sizeof(int) * 2);
		if (!cmd->fd[i])
		{
			while (i >= 0)
				free(cmd->fd[i--]);
			free(cmd->fd);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_pid(t_cmd *cmd)
{
	cmd->pid = malloc(sizeof(int) * cmd->nb_cmd);
	if (!cmd->pid)
		return (1);
	return (0);
}

void	err_exve(void)
{
	write(2, "An error ocurred with execve function", 38);
	write(2, "\n", 2);
}

void	err_cmd(void)
{
	write (2, "permission denied:", 18);
	write(2, "\n", 1);
}

void	close_exit(t_cmd *cmd)
{
	ft_close_all(cmd);
	free_all(cmd);
	exit(EXIT_FAILURE);
}
