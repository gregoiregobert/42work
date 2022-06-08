/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:42:57 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/08 12:44:08 by ggobert          ###   ########.fr       */
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

typedef struct	t_cmd
{
	char	**cmd1;
	char	**cmd2;
	char	**path;
	char	*path_cmd1;
	char	*path_cmd2;
	char	*filein;
	char	*fileout;
}		s_cmd;

void	parsing_gest(int ac, char **av, char **ev, s_cmd *command);
void    err_findp(int find_p, s_cmd *command, int msg_err);
void    err_grbc(s_cmd *command, int _msg_err);
void    err_accessr(s_cmd *command, int msg_err);
char    *access_command1(s_cmd *command, int i);
char    *access_command2(s_cmd *command, int i);
int     find_path(int ac, char **ev, s_cmd *command);
int     grab_cmd(char **av, s_cmd *command);
int     access_right(s_cmd *command);

#endif
