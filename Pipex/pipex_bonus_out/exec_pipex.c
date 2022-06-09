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
    int fd[2];
    int fd_file[2];
    int pid1;
    int pid2;

    if (pipe(fd) == -1)
        return (1);
    fd_file [0] = ft_open(cmd->filein, 1);
    fd_file [1] = ft_open(cmd->fileout, 2);
    if (fd_file[0] < 0 || fd_file[1] < 0)
        return (2);
    pid1 = fork();
    if (pid1 < 0)
        return (3);
    if (pid1 == 0)
        start_pid(fd, fd_file, cmd);
    pid2 = fork();
    if (pid2 < 0)
        return (4);
    if (pid2 == 0)
        end_pid(fd, fd_file, cmd);
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    close(fd_file[0]);
    close(fd_file[1]);
    return(0);
}

int ft_open(char *file, int arg)
{
    int fd;

    if (arg == 1)
    {
        fd = open(file, O_RDONLY, 0777);
        if (fd < 0)
            return (1);
    }
    if (arg == 2)
     {
        fd = open(file, O_CREAT | O_WRONLY, 0777);
        if (fd < 0)
            return (1);
     }
    return (fd);
}

int start_pid(int *fd, int *fd_file, t_cmd *cmd)
{
    close(fd[0]);
    dup2(fd_file[0], STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    execve(cmd->path_cmd1, cmd->cmd1, NULL);
    perror("An error ocurred with execve cmd1 ");
    exit(EXIT_FAILURE);
}

int end_pid(int *fd, int *fd_file, t_cmd *cmd)
{
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    dup2(fd_file[1], STDOUT_FILENO);
    close(fd[0]);
    execve(cmd->path_cmd2, cmd->cmd2, NULL);
    perror("An error ocurred with execve cmd2 ");
    exit(EXIT_FAILURE);
}