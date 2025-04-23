/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:18:19 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/22 14:18:43 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	fd = open("fichier.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while (i < 5)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		i++;
	}
}
