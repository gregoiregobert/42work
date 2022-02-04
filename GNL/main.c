/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:24:30 by ggobert           #+#    #+#             */
/*   Updated: 2022/01/28 15:37:57 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*b;

	i = 0;
	fd = open("get_next_line.c", O_RDONLY);
	if (fd < 0)
		return (0);
	while (i < 150)
	{
		b = get_next_line(fd);
		printf("%s", b);
		free(b);
		i++;
	}
//	system("leaks a.out");
}

/*int	main()
{
	int	fd;
	char	*b;

	fd = open("get_next_line.c", O_RDONLY);
	if (fd < 0)
		return (0);
	b = "1";
	while (b != NULL)
	{
		b = get_next_line(fd);
		printf("%s", b);
		free(b);
	}
	return (0);
//	system("leaks a.out");
}*/
