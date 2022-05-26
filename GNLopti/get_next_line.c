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
	char	*temp;

	count = read(fd, ret, BUFFER_SIZE);
	if (count == 0)
		return (0);
	ret[count] = 0;
	temp = ft_strdup(ret);
	while (ft_check_newline(ret) < 0 && count == BUFFER_SIZE)
	{
		count = read(fd, ret, BUFFER_SIZE);
		ret[count] = 0;
		temp = ft_strjoin(temp, ret);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	char		*readline;
	char		*temp;
	static char	ret[BUFFER_SIZE + 1];

	if (fd < 0 || read(fd, ret, 0) < 0)
		return (0);
	temp = ft_read_until(fd, ret);
	if (!*temp)
		return (0);
	readline = malloc(sizeof(char) * (ft_len_newline(temp) + 1));
	if (!readline)
		return (0);
	i = 0;
	j = 0;
	if (ft_check_newline(temp) < 1 && *ret);
	{
		while (ret[i])
			readline[i] = ret[i];
	}
	while (i++ < ft_len_newline(temp))
		readline[i] = temp[j];
	readline[i] = 0;
	ret = ft_strnback(ret, ft_len_newline(ret));
	return (readline);
}
