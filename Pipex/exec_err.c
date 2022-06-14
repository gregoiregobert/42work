/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:40:25 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/14 16:40:28 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    execution_manager(t_cmd *cmd)
{
    int err;

    if (init_fd(cmd) == 1 || init_pid(cmd) == 1)
        err_init(cmd, 1);
    err = execute_cmd(cmd);
    if (err == 1)
        err_pipe(cmd);
    if (err == 2)
        err_open(cmd);
    if (err == 3)
        err_fork(cmd);
}

void    err_init(t_cmd *cmd, int msg)
{
    perror("An error ocurred with malloc of fd or pid ");
    exit(EXIT_FAILURE);
}

void    err_pipe(t_cmd *cmd)
{
    free_all(cmd);
    perror("An error ocurred with the pipe function ");
    exit(EXIT_FAILURE);
}

void    err_open(t_cmd *cmd)
{
    free_all(cmd);
    perror("An error ocurred with the open function ");
    exit(EXIT_FAILURE);
}

void    err_fork(t_cmd *cmd)
{
    free_all(cmd);
    perror("An error ocurred with the fork function ");
    exit(EXIT_FAILURE);  
}