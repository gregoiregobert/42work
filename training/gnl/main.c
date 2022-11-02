/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:14:48 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/02 15:36:56 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	main(int ac, char **av)
{
	int fd;
	char *buff;
	int i;
	
	(void)ac;
	i = -1;
	buff = 0;
	fd = open(av[1], O_RDONLY);
	while (++i < 50)
	{
		buff = gnl(fd);
		printf("%s", buff);
		free(buff);
	}
	close(fd);
}
