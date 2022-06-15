/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:51:13 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/14 16:15:56 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->nb_cmd)
		if (pipe(cmd->fd[i++]) == -1)
			return (1);
	i = 0;
	if (ft_open(cmd) == 1)
		return (2);
	while (i < cmd->nb_cmd)
	{
		cmd->pid[i] = fork();
		if (cmd->pid[i] < 0)
			return (3);
		if (cmd->pid[i] == 0)
			multi_pid(i, cmd);
		i++;
	}
	i = -1;
	ft_close_all(cmd);
	while (++i < cmd->nb_cmd)
		wait(NULL);
	return (0);
}

int	ft_open(t_cmd *cmd)
{
	cmd->fd_file = malloc(sizeof(int) * 2);
	cmd->fd_file[0] = open(cmd->filein, O_RDONLY, 0777);
	if (cmd->fd_file[0] < 0)
		return (1);
	cmd->fd_file[1] = open(cmd->fileout, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (cmd->fd_file[1] < 0)
		return (1);
	return (0);
}

void	ft_close_all(t_cmd *cmd)
{
	int	j;
	int	x;

	j = 0;
	while (j < cmd->nb_cmd)
	{
		x = 0;
		while (x < 2)
			close(cmd->fd[j][x++]);
		j++;
	}
	close(cmd->fd_file[0]);
	close(cmd->fd_file[1]);
}

int	multi_pid(int i, t_cmd *cmd)
{
	printf("process num %d\n", i);
	if (i == 0)
		dup2(cmd->fd_file[0], STDIN_FILENO);
	else
		dup2(cmd->fd[i][0], STDIN_FILENO);
	if (i == cmd->nb_cmd - 1)
		dup2(cmd->fd_file[1], STDOUT_FILENO);
	else
		dup2(cmd->fd[i + 1][1], STDOUT_FILENO);
	ft_close_all(cmd);
	execve(cmd->path_cmd[i], cmd->cmd[i], NULL);
	perror("An error ocurred with a execve ");
	return (i + 2);
}
