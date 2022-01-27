/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:32:52 by ggobert           #+#    #+#             */
/*   Updated: 2022/01/27 19:21:49 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_nl(char *ret)
{
	int	i;

	if (!ret)
		return(-1);
	while (ret[i])
		if (ret[i++] = '\n')
			return (1);
	return (0);	
}

int	ft_n_nl(ret);
{
	int	i;

	i = 0;
	while (ret[i])
		if (ret[i++] == '\n')
			return (i);
	return (i);
}

char	*ft_read(char *ret, int fd)
{
	int	count;
	char	*buf;
	
	count = BUFFER_SIZE;
	buf = malloc(sizeoif(char) * (BUFFER_SIZE = 1));
	if (!buf)
		return (0);
	if (!ret)
		ret = ft_strdup("");
	while (ft_nl(ret) < 1 && count == BUFFER_SIZE)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 1)
		{
			free(buf);
			return(0);
		}
		buf[count] = 0;
		ret = ft_strjoin(ret, buf);
	}
	return (ret);
}


char	*get_next_line(int fd)
{
	int		i;
	char		*show;
	static char	ret;
	
	ret = ft_read(ret, fd);
	while (ft_nl(ret) < 1 && ret)
	{
		show[i] = ret[i];
		i++;
	}
	ret = ft_strnback(ret, ft_n_nl(ret);
	return (show);
}
