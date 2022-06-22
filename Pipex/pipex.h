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
# include <sys/types.h>

typedef struct s_cmd
{
	char	***cmd;
	char	**path;
	char	**path_cmd;
	char	*filein;
	char	*fileout;
	int		**fd;
	int		*fd_file;
	int		*pid;
	int		nb_cmd;
	int		err;

}		t_cmd;

void	parsing_gest(int ac, char **av, char **ev, t_cmd *command);
void	err_findp(t_cmd *command, int msg_err);
void	err_grbc(t_cmd *command, int _msg_err);
void	err_accessr(t_cmd *command);
void	err_ncmd(void);
void	err_init(t_cmd *cmd);
void	err_pipe(t_cmd *cmd);
void	err_open(t_cmd *cmd, char **av);
void	err_fork(t_cmd *cmd);
void	err_exve(void);
void	err_cmd(void);
void	ft_close_all(t_cmd *cmd);
void	free_all(t_cmd *command);
void	free_fd_pid(t_cmd *cmd);
void	execution_manager(t_cmd *cmd, char **ev, char **av);
void	path_zero(t_cmd *cmd, int l);
void	err_msg(t_cmd *cmd, int l);
void	env_null(void);
void	close_exit(t_cmd *cmd);
char	*access_command(t_cmd *command, int i, int l);
int		nbof_cmd(int ac, t_cmd *cmd);
int		find_path(char **ev, t_cmd *command);
int		grab_cmd(char **av, t_cmd *command);
int		access_right(t_cmd *command);
int		execute_cmd(t_cmd *cmd, char **ev);
int		ft_open(t_cmd *cmd);
int		multi_pid(int i, t_cmd *cmd, char **ev, int err);
int		init_fd(t_cmd *cmd);
int		init_pid(t_cmd *cmd);

#endif
