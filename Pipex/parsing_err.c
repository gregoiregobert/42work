/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:59:32 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/15 11:48:23 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing_gest(int ac, char **av, char **ev, t_cmd *command)
{
	int	find_p;
	int	grb_c;
	int	access_r;
	int	n_cmd;

	n_cmd = nbof_cmd(ac, command);
	if (n_cmd != 0)
		err_ncmd();
	find_p = find_path(ev, command);
	if (find_p != 0)
		err_findp(command, 1);
	grb_c = grab_cmd(av, command);
	if (grb_c != 0)
	{
		err_findp(command, 0);
		err_grbc(command, 1);
	}
	access_r = access_right(command);
	if (access_r != 0)
	{
		err_findp(command, 0);
		err_grbc(command, 0);
		err_accessr(command);
	}
}

void	err_ncmd(void)
{
	write(2, "An error ocurred with number of arguments.", 42);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	err_findp(t_cmd *command, int msg_err)
{
	int	i;

	i = 0;
	if (command->path)
	{
		while (command->path[i])
			free(command->path[i++]);
		free(command->path);
	}
	if (msg_err == 1)
	{
		write(2, "An error occured with env Path", 31);
		write(2, "\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	err_grbc(t_cmd *command, int msg_err)
{
	int	i;
	int	j;

	j = 0;
	while (command->cmd[j])
	{
		i = 0;
		while (command->cmd[j][i])
			free(command->cmd[j][i++]);
		free(command->cmd[j++]);
	}
	if (command->cmd)
		free(command->cmd);
	if (msg_err == 1)
	{
		perror("An error ocurred with malloc of command ");
		exit(EXIT_FAILURE);
	}
}

void	err_accessr(t_cmd *command)
{
	int	j;

	j = -1;
	if (command->path_cmd)
	{
		while (++j < command->nb_cmd)
		{
			if (command->path_cmd[j])
				free(command->path_cmd[j]);
		}
		free(command->path_cmd);
	}
}
