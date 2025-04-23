/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:59:39 by ggobert           #+#    #+#             */
/*   Updated: 2022/01/27 18:02:27 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_check_newline(char *ret)
{
	int	i;

	i = 0;
	if (!ret)
		return (0);
	while (ret[i])
		if (ret[i++] == '\n')
			return (1);
	return (-1);
}

int	ft_len_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (i);
	return (i);
}

char	*ft_read_until(int fd, char *ret)
{
	ssize_t	count;
	char	*buf;

	count = BUFFER_SIZE;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	if (!ret)
		ret = ft_strdup("");
	while (ft_check_newline(ret) < 0 && count == BUFFER_SIZE)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 1 && !*ret)
		{
			if (!*ret)
				free(ret);
			free(buf);
			return (0);
		}
		buf[count] = 0;
		ret = ft_strjoin(ret, buf);
	}
	free(buf);
	return (ret);
}

char	*get_next_line(int fd, int check)
{
	int			i;
	char		*readline;
	static char	*ret;

	i = -1;
	if (check)
		return(free(ret), NULL);
	if (fd < 0 || read(fd, ret, 0) < 0)
		return (0);
	if (ft_check_newline(ret) < 0 || !ret)
		ret = ft_read_until(fd, ret);
	if (!ret)
		return (0);
	if (!*ret)
		return (free (ret), NULL);
	readline = malloc(sizeof(char) * (ft_len_newline(ret) + 1));
	if (!readline)
		return (0);
	while (++i < ft_len_newline(ret))
		readline[i] = ret[i];
	readline[i] = 0;
	ret = ft_strnback(ret, ft_len_newline(ret));
	return (readline);
}
