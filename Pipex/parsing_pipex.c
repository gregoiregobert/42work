/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:19:27 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/08 12:42:47 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int grab_cmd(char **av, s_cmd *command)
{
	command->filein = av[1];
	command->cmd1 = ft_split(av[2], ' ');
	command->cmd2 = ft_split(av[3], ' ');
	command->fileout = av[4];
	if (command->cmd1 == 0 || command->cmd2 == 0)
		return (1);
	return (0);
}

char    *access_command1(s_cmd *command, int i)
{
	char    *path_access;
	int     k;
	int     j;

	k = -1;
	j = k;
	path_access = malloc(sizeof(char) * (ft_strlen(command->path[i]) + ft_strlen(command->cmd1[0]) + 2));
	if (!path_access)
		return (0);
	while (command->path[i][++k])
		path_access[k] = command->path[i][k];
	path_access[k++] = '/';
	while (command->cmd1[0][++j])
		path_access[k++] = command->cmd1[0][j]; 
	path_access[k] = 0;
	return (path_access);
}

char    *access_command2(s_cmd *command, int i)
{
	char    *path_access;
	int     k;
	int     j;

	k = -1;
	j = k;
	path_access = malloc(sizeof(char) * (ft_strlen(command->path[i]) + ft_strlen(command->cmd2[0]) + 2));
	if (!path_access)
		return (0);
	while (command->path[i][++k])
		path_access[k] = command->path[i][k];
	path_access[k++] = '/';
	while (command->cmd2[0][++j])
		path_access[k++] = command->cmd2[0][j]; 
	path_access[k] = 0;
	return (path_access);
}

int access_right(s_cmd *command)
{
	int i;
	int j;
	int sizeEv;

	sizeEv = 0;
	while (command->path[sizeEv])
		sizeEv++;
	i = --sizeEv;
	j = i;
	command->path_cmd1 = access_command1(command, i--);
	while (access(command->path_cmd1, X_OK) == -1 && i != 0)
	{
		free (command->path_cmd1);
		command->path_cmd1 = access_command1(command, i--);
	}
	command->path_cmd2 = access_command2(command, j--);
	while (access(command->path_cmd2, X_OK) == -1 && j != 0)
	{
		free(command->path_cmd2);
		command->path_cmd2 = access_command2(command, j--);
	}
	if (i == 0 || j == 0)
		return (1);
	return (0);
}

int    find_path(int ac, char **ev, s_cmd *command)
{
	if (ac != 5)
		return (1);
	while (*ev)
	{
		if (ft_strncmp(*ev , "PATH=", 5) == 0)
			command->path = ft_split(*ev, ':');
		ev++;
	}
	if (command->path == 0)
		return (2);
	return (0);
}
