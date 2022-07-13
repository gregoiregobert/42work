/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:30:13 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/07 16:30:15 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing(char **av, t_data *data)
{
	int		fd;
	int		i;

	fd = open_fd(av);
	data->map = malloc(sizeof(char*) * (data->height_window + 1));
	if (!data->map)
		perror_exit();
	i = -1;
	while (++i < data->height_window)
	{
		data->map[i] = malloc(sizeof(char) * (data->width_window));
		if (!data->map[i])
		{
			free_map(data);
			perror_exit();
		}
		data->map[i] = get_next_line(fd);
		data->map[i][strlen(data->map[i]) - 1] = 0;
	}
	data->map[i] = 0;
	close(fd);
}
