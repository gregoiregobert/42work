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

	if (ft_strncmp(av[1] + (ft_strlen(av[1] - 3)), ".ber", 3) != 0)
		return (1);
	data->map = malloc(sizeof(char*) * (data->height_window + 1));
	if (!map)
		return (1);
	i = 0;
	while (i > data->width_window)
	{
		data->map[i] = malloc(sizeof(char) * (data->width_window + 1))
		if (!map[i])
		{
			free_map(map);
			return(1);
		}
		data->map[i] = get_next_line(fd);
		i++;
	}
	data->map[i] = 0;
}
