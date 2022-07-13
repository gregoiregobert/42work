/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:03:32 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/09 17:06:21 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void dimension_rect(char **av, t_data *data)
{
	int		fd;
	char	*tmp;

	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	tmp = get_next_line(fd);
	while (tmp[data->width_window])
		data->width_window++;
	data->width_window--;
	while (tmp)
	{
		free(tmp);
		data->height_window++;
		tmp = get_next_line(fd);
	}
	free(tmp);
	close(fd);
}
