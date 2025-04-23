/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:18:40 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/03 13:08:39 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rm_lastmove(t_data *data)
{
	int		i;
	char	*tmp;

	i = -1;
	if (!data->way.move)
		return ;
	tmp = ft_strdup(data->way.move);
	free(data->way.move);
	data->way.move = malloc(ft_strlen(tmp));
	while (tmp[++i + 1])
		data->way.move[i] = tmp[i];
	data->way.move[i] = 0;
	free(tmp);
}

char	backtrack_move(t_data *data)
{
	int	i;

	i = 0;
	while (data->way.move[i])
		i++;
	i--;
	return (data->way.move[i]);
}

void	new_move(t_data *data, char c)
{
	int		i;
	char	*tmp;

	i = -1;
	if (data->way.move == 0)
	{
		init_move(data, c);
		return ;
	}
	tmp = ft_strdup(data->way.move);
	free(data->way.move);
	data->way.move = malloc(ft_strlen(tmp) + 2);
	while (tmp[++i])
	{
		data->way.move[i] = tmp[i];
	}
	data->way.move[i++] = c;
	data->way.move[i] = 0;
	free(tmp);
}

void	init_move(t_data *data, char c)
{
	int	i;

	i = 0;
	data->way.move = malloc(2);
	if (!data->way.move)
		perror_exit();
	data->way.move[i++] = c;
	data->way.move[i] = 0;
}
