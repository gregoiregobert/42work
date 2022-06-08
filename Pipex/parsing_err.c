/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:59:32 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/08 13:45:01 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing_gest(int ac, char **av, char **ev, t_cmd *command)
{
	int	find_p;
	int	grb_c;
	int	access_r;

	find_p = find_path(ac, ev, command);
	if (find_p != 0)
		err_findp(find_p, command, 1);
	grb_c = grab_cmd(av, command);
	if (grb_c != 0)
	{
		err_findp(2, command, 0);
		err_grbc(command, 1);
	}
	access_r = access_right(command);
	if (access_r != 0)
	{
		err_findp(2, command, 0);
		err_grbc(command, 0);
		err_accessr(command, 1);
	}
}

void	err_findp(int find_p, t_cmd *command, int msg_err)
{
	int	i;

	i = 0;
	if (find_p == 1 && msg_err == 1)
	{
		perror("An error ocurred with number of arguments ");
		exit(EXIT_FAILURE);
	}
	if (find_p == 2)
	{
		while (command->path[i])
			free(command->path[i++]);
		if (command->path)
			free(command->path);
		if (msg_err == 1)
		{
			perror("An error occured with malloc env Path ");
			exit(EXIT_FAILURE);
		}
	}
}

void	err_grbc(t_cmd *command, int msg_err)
{
	int	i;

	i = 0;
	while (command->cmd1[i])
		free(command->cmd1[i++]);
	if (command->cmd1)
		free(command->cmd1);
	i = 0;
	while (command->cmd2[i])
		free(command->cmd2[i++]);
	if (command->cmd2)
		free(command->cmd2);
	if (msg_err == 1)
	{
		perror("An error ocurred with malloc of command ");
		exit(EXIT_FAILURE);
	}
}

void	err_accessr(t_cmd *command, int msg_err)
{
	free(command->path_cmd1);
	free(command->path_cmd2);
	if (msg_err == 1)
	{
		perror("Command not found ");
		exit(EXIT_FAILURE);
	}
}
