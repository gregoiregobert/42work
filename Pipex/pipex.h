/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:42:57 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/08 13:33:41 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char	***cmd;
	char	**path;
	char	**path_cmd;
	char	*filein;
	char	*fileout;
	int		nb_cmd;
	int		*fd_file;
}		t_cmd;

void	parsing_gest(int ac, char **av, char **ev, t_cmd *command);
void	err_findp(t_cmd *command, int msg_err);
void	err_grbc(t_cmd *command, int _msg_err);
void	err_accessr(t_cmd *command, int msg_err);
void	err_ncmd();
void    ft_wait(int *pid, t_cmd *cmd);
void	free_all();
char	*access_command(t_cmd *command, int i, int l);
int 	nbof_cmd(int ac, t_cmd *cmd);
int		find_path(char **ev, t_cmd *command);
int		grab_cmd(char **av, t_cmd *command);
int		access_right(t_cmd *command);
int		execute_cmd(t_cmd *cmd);
int		ft_open(t_cmd *cmd);
int 	**init_fd(t_cmd *cmd);

void    ft_close_all(int **fd, t_cmd *cmd);
int		multi_pid(int i, int **fd, t_cmd *cmd);

#endif
