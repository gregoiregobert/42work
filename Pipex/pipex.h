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
}		t_cmd;

void	parsing_gest(int ac, char **av, char **ev, t_cmd *command);
void	err_findp(int find_p, t_cmd *command, int msg_err);
void	err_grbc(t_cmd *command, int _msg_err);
void	err_accessr(t_cmd *command, int msg_err);
void	err_ncmd();
char	*access_command(t_cmd *command, int i, int l);
int		find_path(char **ev, t_cmd *command);
int		grab_cmd(char **av, t_cmd *command);
int		access_right(t_cmd *command);
int		execute_cmd(t_cmd *cmd);
int		ft_open(char *file, int arg);
int 	start_pid(int *fd, int *fd_file, t_cmd *cmd);
int 	end_pid(int *fd, int *fd_file, t_cmd *cmd);
int 	nbof_cmd(int ac, t_cmd *cmd);

#endif
