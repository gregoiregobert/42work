/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipex2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:18:28 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/15 11:46:48 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	nbof_cmd(int ac, t_cmd *cmd)
{
	if (ac < 5)
		return (1);
	else
		cmd->nb_cmd = ac - 3;
	return (0);
}

void	err_msg(t_cmd *cmd, int l)
{
	write(2, "command not found: ", 20);
	write(2, cmd->cmd[l][0], ft_strlen(cmd->cmd[l][0]));
	write(2, "\n", 1);
}
