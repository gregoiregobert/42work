/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:59:32 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/07 15:59:38 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing_gest(int ac, char **av, char **ev, s_cmd *command)
{
    int find_p;
    int grb_c;
    int access_r;

    find_p = find_path(ev, command);
    if (find_p != 0)
        err_findp(command);
    grb_c = grab_cmd(ac, av, command);
    if (grb_c != 0)
        err_grbc(grb_c, command);
    access_r = access_right(command);
    if (access_r != 0)
        err_accessr(command);
}

void    err_findp(s_cmd *command)
{
    perror("An error occured with malloc env Path.");
    while (*command->path)
        free(*command->path++);
    free(command->path);
    exit(EXIT_FAILURE);
}

void    err_grbc(int grb_c, s_cmd *command)
{
    if (grb_c == 1)
    {
        perror("An error ocurred with number of arguments.");
        exit(EXIT_FAILURE);
    }
    if (grb_c == 2)
    {
        perror("An error ocurred with malloc of command");
        while (*command->cmd1)
            free(*command->cmd1++);
        if (command->cmd1)
            free(command->cmd1);
        while (*command->cmd2)
            free(*command->cmd2);
        if (command->cmd2)
            free(command->cmd2);
        exit(EXIT_FAILURE);
    }
}

void    err_accessr(s_cmd *command)
{
    perror("Command not found.");
        if (command->path_cmd1)
            free(command->path_cmd1);
        if (command->path_cmd2)
            free(command->path_cmd2);
        exit(EXIT_FAILURE);
}
