/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:14:48 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/01 17:07:04 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	main(int ac, char **av)
{
	int fd;
	char *buff;
	
	fd = open(av[--ac], O_RDONLY);
	buff = gnl(fd);
	while (buff)
	{
		printf("%s", buff);
		buff = gnl(fd);
	}
	free(buff);
}