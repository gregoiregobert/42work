/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:32:52 by ggobert           #+#    #+#             */
/*   Updated: 2022/02/04 15:17:04 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_nl(char *ret)
{
	int	i;

	i = 0;
	if (!ret)
		return(-1);
	while (ret[i])
		if (ret[i++] == '\n')
			return (1);
	return (0);	
}

int	ft_n_nl(char *ret)
{
	int	i;

	i = 0;
	while (ret[i])
		if (ret[i++] == '\n')
			return (i);
	return (i);
}

char	*ft_read(char *show, int fd)
{
	int	count;
	char	*buf;
	
	count = BUFFER_SIZE;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	if (!show)
		show = ft_strdup("");
	while (ft_nl(show) < 1 && count == BUFFER_SIZE)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 1)
		{
			free(buf);
			return(0);
		}
		buf[count] = 0;
		show = ft_strjoin(show, buf);
	}
	return (show);
}


char	*get_next_line(int fd)
{
	int			i;
	int 		len;
	char		*show;
	static char	ret[BUFFER_SIZE + 1];
	
	show = ft_read(show, fd);
	ret = after_line(show, ft_n_nl(show));
	show = cut_at(show, ft_n_nl(show));
	return (show);
}
