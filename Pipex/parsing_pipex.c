/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:19:27 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/08 13:40:05 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	grab_cmd(char **av, t_cmd *command)
{
	int i;

	i = 1;
	command->filein = av[i++];
	command->cmd = malloc(sizeof(char **) * (command->nb_cmd + 1));
	while (i < command->nb_cmd + 2)
	{
		command->cmd[i - 2] = ft_split(av[i], ' ');
		i++;
	}
	command->cmd[i - 2] = 0;
	command->fileout = av[i];
	i = command->nb_cmd;
	while (i-- > 0)
		if (command->cmd[i] == 0)
			return (1);
	return (0);
}

char	*access_command(t_cmd *command, int i, int l)
{
	char	*path_access;
	int		k;
	int		j;

	k = -1;
	j = k;
	path_access = malloc(sizeof(char)
			* (ft_strlen(command->path[i]) + ft_strlen(command->cmd[l][0]) + 2));
	if (!path_access)
		return (0);
	while (command->path[i][++k])
		path_access[k] = command->path[i][k];
	path_access[k++] = '/';
	while (command->cmd[l][0][++j])
		path_access[k++] = command->cmd[l][0][j];
	path_access[k] = 0;
	return (path_access);
}

int	access_right(t_cmd *command)
{
	int	i;
	int	l;
	int	sizeev;

	sizeev = 0;
	l = 0;
	command->path_cmd = malloc(sizeof(char *) * (command->nb_cmd + 1));
	while (command->path[sizeev])
		sizeev++;
	while (l < command->nb_cmd)
	{
		i = sizeev - 1;
		command->path_cmd[l] = access_command(command, i--, l);
		while (access(command->path_cmd[l], X_OK) == -1 && i != 0)
		{
			free (command->path_cmd[l]);
			command->path_cmd[l] = access_command(command, i--, l);
		}
		if (i == 0)
			return (1);
		l++;
	}
	command->path_cmd[l] = 0;
	return (0);
}

int	find_path(char **ev, t_cmd *command)
{
	while (*ev)
	{
		if (ft_strncmp(*ev, "PATH=", 5) == 0)
			command->path = ft_split(*ev, ':');
		ev++;
	}
	if (command->path == 0)
		return (2);
	return (0);
}