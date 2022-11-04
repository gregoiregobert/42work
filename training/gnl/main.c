/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:59:35 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/04 12:01:44 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	main(int ac, char **av)
{
	int	fd;
	char	*buff;

	fd = open(av[1], O_RDONLY);
	buff = gnl(fd);
	while (buff)
	{
		printf("%s", buff);
		free(buff);
		buff = gnl(fd);
	}
}