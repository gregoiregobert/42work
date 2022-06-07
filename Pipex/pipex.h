/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:42:57 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/06 16:43:05 by ggobert          ###   ########.fr       */
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

typedef struct  t_cmd
{
    char    **cmd1;
    char    **cmd2;
    char    **access_path;
}               s_cmd;

int    access_command(s_cmd *command);
char    **find_path(char **ev);
void    parsing(int ac, char **av, s_cmd *command);

#endif