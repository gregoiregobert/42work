/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:29:46 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/08 13:35:18 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **ev)
{
	t_cmd	command;

	parsing_gest(ac, av, ev, &command);
	execution_manager(&command, ev, av);
	free_all(&command);
	return (0);
}
