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

void    parsing(int ac, char **av, s_cmd *command)
{
    if (ac != 5)
        return ;
    command->cmd1 = ft_split(av[2], ' ');
    command->cmd2 = ft_split(av[3], ' ');
}

char    access_command(s_cmd *command)
{
    char *path_access;
 
    path_access = ft_strdup("");
    path_access = ft_strjoin(path_access, command->access_path[1]);
    path_access = ft_strjoin(path_access, "/");
    path_access = ft_strjoin(path_access, command->cmd1[0]);
    printf("path_access = %s\n", path_access);
    return (path_access);
}

void    access_right(s_cmd command)