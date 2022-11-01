/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:51:13 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/21 11:44:21 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_cmd(t_cmd *cmd, char **ev)
{
	int	i;

	i = 0;
	//________pipe init
	while (i < cmd->nb_cmd)
		if (pipe(cmd->fd[i++]) == -1)
			return (1);
	//________open redir
	cmd->err = ft_open(cmd);
	//________fork
	i = 0;
	while (i < cmd->nb_cmd)
	{
		cmd->pid[i] = fork();
		if (cmd->pid[i] < 0)
			return (3);
	//________process
		if (cmd->pid[i] == 0)
			multi_pid(i, cmd, ev, cmd->err);
		i++;
	}
	i = -1;
	//________close all fd
	ft_close_all(cmd);
	//________WAIT
	while (++i < cmd->nb_cmd)
		wait(NULL);
	if (cmd->err != 0)
		return (2);
	return (0);
}

int	ft_open(t_cmd *cmd)
{
	cmd->fd_file = malloc(sizeof(int) * 2);
	cmd->fd_file[1] = open(cmd->fileout, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (cmd->fd_file[1] < 0)
		cmd->err += 2;
	cmd->fd_file[0] = open(cmd->filein, O_RDONLY);
	if (cmd->fd_file[0] < 0)
		cmd->err += 1;
	return (cmd->err);
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
	if (cmd->fd_file[0] >= 0)
		close(cmd->fd_file[0]);
	if (cmd->fd_file[1] >= 0)
		close(cmd->fd_file[1]);
}

int	multi_pid(int i, t_cmd *cmd, char **ev, int err)
{
	//cas d'err
	if ((err == 1 || err == 3) && i == 0)
		close_exit(cmd);
	if (err >= 2 && i == cmd->nb_cmd - 1)
		close_exit(cmd);
	//dup
	if (i == 0)
		dup2(cmd->fd_file[0], STDIN_FILENO);
	else
		dup2(cmd->fd[i][0], STDIN_FILENO);
	if (i == cmd->nb_cmd - 1)
		dup2(cmd->fd_file[1], STDOUT_FILENO);
	else
		dup2(cmd->fd[i + 1][1], STDOUT_FILENO);
	//close all fd
	ft_close_all(cmd);
	//execve
	if (ft_strncmp(cmd->cmd[i][0], "\0", 1) == 0
			&& cmd->err != i + 1 && cmd->err != 3)
		err_cmd();
	if (execve(cmd->path_cmd[i], cmd->cmd[i], ev) == -1
		&& access(cmd->path_cmd[i], X_OK) != -1
		&& ft_strncmp(cmd->cmd[i][0], "\0", 1) != 0)
		err_exve();
	free_all(cmd);
	exit(EXIT_FAILURE);
}
