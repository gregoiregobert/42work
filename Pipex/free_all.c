/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:49:38 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/15 11:42:29 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_cmd *command)
{
	err_findp(command, 0);
	err_grbc(command, 0);
	err_accessr(command);
	free_fd_pid(command);
}

void	free_fd_pid(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->pid)
		free(cmd->pid);
	if (cmd->fd)
	{
		while (i < cmd->nb_cmd)
			free(cmd->fd[i++]);
		free(cmd->fd);
	}
	if (cmd->fd_file)
		free(cmd->fd_file);
}
