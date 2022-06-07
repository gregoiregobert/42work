/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:19:27 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/06 17:19:32 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int grab_cmd(int ac, char **av, s_cmd *command)
{
    if (ac != 5)
        return (1) ;
    command->filein = av[1];
    command->cmd1 = ft_split(av[2], ' ');
    command->cmd2 = ft_split(av[3], ' ');
    command->fileout = av[4];
    if (command->cmd1 == 0 || command->cmd2 == 0)
        return (2);
    return (0);
}

char    *access_command1(s_cmd *command, int i)
{
    char *path_access;
 
    path_access = ft_strdup("");
    path_access = ft_strjoin(path_access, command->path[i]);
    path_access = ft_strjoin(path_access, "/");
    path_access = ft_strjoin(path_access, command->cmd1[0]);
    return (path_access);
}

char    *access_command2(s_cmd *command, int i)
{
    char *path_access;
 
    path_access = ft_strdup("");
    path_access = ft_strjoin(path_access, command->path[i]);
    path_access = ft_strjoin(path_access, "/");
    path_access = ft_strjoin(path_access, command->cmd2[0]);
    return (path_access);
}

int access_right(s_cmd *command)
{
    int i;
    int sizeEv;

    sizeEv = 0;
    while (command->path[sizeEv])
        sizeEv++;
    i = sizeEv;
    command->path_cmd1 = access_command1(command, i--);
    while (access(command->path_cmd1, X_OK) == -1 && i != 0)
        command->path_cmd1 = access_command1(command, i--);
    if (i == 0)
        command->path_cmd1 = 0;
    i = sizeEv;
    command->path_cmd2 = access_command2(command, i--);
    while (access(command->path_cmd2, X_OK) == -1 && i != 0)
        command->path_cmd2 = access_command2(command, i--);
    if (i == 0)
        command->path_cmd2 = 0;
    if (command->path_cmd1 == 0 || command->path_cmd2 == 0)
        return (1);
    return (0);
}

int    find_path(char **ev, s_cmd *command)
{
    while (*ev)
    {
        if (ft_strncmp(*ev , "PATH=", 5) == 0)
            command->path = ft_split(*ev, ':');
        ev++;
    }
    if (command->path == 0)
        return (1);
    return (0);
}
