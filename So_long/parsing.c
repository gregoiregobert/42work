/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:30:13 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/19 14:31:39 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing(char **av, t_data *data)
{
	int		fd;
	int		i;

	fd = open_fd(av);
	data->map = malloc(sizeof(char *) * (data->height_window + 1));
	if (!data->map)
		perror_exit();
	i = -1;
	while (++i < data->height_window)
	{
		data->map[i] = get_next_line(fd);
		data->map[i] = cut_nl(data->map[i]);
	}
	data->map[i] = 0;
	close(fd);
}
