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

int    execute_cmd(t_cmd *cmd)
{
    int **fd;
    int pid[cmd->nb_cmd];
    int i;
    int j;

    i = 0;
    j = cmd->nb_cmd;
    fd = malloc(sizeof(int *) * cmd->nb_cmd);
// init pipe
    while (j < cmd->nb_cmd)
        if (pipe(fd[j++]) == -1)
            return (1);
// open file
    if (ft_open(cmd) == 1)
        return (2);
// fork
    while (i < cmd->nb_cmd)
    {
        pid[i] = fork();
        if (pid[i] < 0)
            return (3);
        if (pid[i] == 0)
            multi_pid(i, fd, cmd);
        i++;
    }
    ft_close_all(fd, cmd);
    ft_wait(pid ,cmd);
    return(0);
}

int ft_open(t_cmd *cmd)
{
    cmd->fd_file = malloc(sizeof(int) * 2);
    cmd->fd_file[0] = open(cmd->filein, O_RDONLY, 0777);
    if (cmd->fd_file[0] < 0)
        return (1);
    cmd->fd_file[1] = open(cmd->fileout, O_CREAT | O_WRONLY, 0777);
    if (cmd->fd_file[1] < 0)
        return (1);
    return (0);
}

void    ft_close(int i, int **fd, t_cmd *cmd)
{
    int j;
    int x;
    
    j = 0;
    while (j < cmd->nb_cmd)
    {
        x = 0;
        while (x < 2)
        {
            if ((j != i - 1 && x != 0) || (j != i && x != 1))
                close(fd[j][x]);
            x++;
        }
        j++;
    }
}

void    ft_close_all(int **fd, t_cmd *cmd)
{
    int j;
    int x;

    while (j < cmd->nb_cmd)
    {
        x = 0;
        while (x < 2)
            close(fd[j][x++]);
        j++;
    }
}

void    ft_wait(int *pid, t_cmd *cmd)
{
    int i;

    i = 0;
    while (i < cmd->nb_cmd)
        waitpid(pid[i], NULL, 0);
}

int multi_pid(int i, int **fd, t_cmd *cmd)
{
    ft_close(i, fd, cmd);
    if (i == 0)
        dup2(cmd->fd_file[0], STDIN_FILENO);
    else
        dup2(fd[i - 1][0], STDIN_FILENO);
    if (i == cmd->nb_cmd)
        dup2(cmd->fd_file[1], STDOUT_FILENO);
    else
        dup2(fd[i][1], STDIN_FILENO);
    close(fd[i - 1][0]);
    close(fd[i][1]);
    execve(cmd->path_cmd[i], cmd->cmd[i], NULL);
    perror("An error ocurred with a execve ");
    return (i + 2);
}
