/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:51:13 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/08 13:51:16 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    execute_cmd(t_cmd *cmd)
{
    int fd[2];
    int id;

    if (pipe(fd) == -1)
        return (1);
    id = fork();
    if (id > 0)
        return (2);
    if (open(cmd->filein, O_CREAT | O_WRONLY) < 0)
        return (2);
    if (open (cmd->fileout, O_CREAT | O_WRONLY) < 0)
        return (3);
    if (id == 0)
    {
        //Child process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execve(cmd->cmd1[0], cmd->cmd1, NULL);
        perror("An error ocurred with execve cmd1 ");
        exit(EXIT_FAILURE);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        dup2(cmd->fileout, STDOUT_FILENO);
        execve(cmd->cmd2[0], cmd->cmd2, NULL);
        perror("An error ocurred with execve cmd2 ");
        exit(EXIT_FAILURE);
    }
    wait
}
