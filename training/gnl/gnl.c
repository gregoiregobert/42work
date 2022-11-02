/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:12:57 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/02 15:39:37 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*gnl(int fd)
{
	static char	rest[BUFFER_SIZE + 1];
	char		*buff;
	char		*tmp;
	int 		count;

	tmp = 0;
	if (fd < 0 || read(fd, rest, 0) < 0)
		return (0);
	if (*rest)
		tmp = ft_strjoin_free(tmp, rest, 1, 0);
	if (!is_nl(tmp))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (0);
		count = read(fd, buff, BUFFER_SIZE);
		buff[count] = 0;
		if (!tmp)
			tmp = ft_strdup(buff);
		else
			tmp = ft_strjoin_free(tmp, buff, 1, 0);
		while (count == BUFFER_SIZE && !is_nl(tmp))
		{
			count = read(fd, buff, BUFFER_SIZE);
			buff[count] = 0;
			tmp = ft_strjoin_free(tmp, buff, 1, 0);
		}
	}
	after_nl(tmp, rest);
	tmp = before_nl(tmp);
	if (buff)
		free(buff);
	return (tmp);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	new = malloc(i + 1);
	if (!new)
		return (0);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	new[i] = 0;
	return (new);
}

int	is_nl(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin_free(char *str1, char *str2, int free_s1, int free_s2)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = -1;
	if (str1)
		while (str1[i])
			i++;
	if (str2)
		while (str2[++j])
			i++;
	tmp = malloc(i + 1);
	if (!tmp)
		return (0);
	i = -1;
	j = -1;
	if (str1)
		while (str1[++i])
			tmp[++j] = str1[i];
	i = -1;
	if (str2)
		while (str2[++i])
			tmp[++j] = str2[i];
	tmp[++j] = 0;
	if (free_s1 && str1)
		free(str1);
	if (free_s2 && str2)
		free(str2);
	return (tmp);
}

void	after_nl(char *tmp, char *rest)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	if (!tmp)
		return ;
	while (tmp[++i])
		if (tmp[i] == '\n')
			break ;
	while (tmp[++i])
		rest[++j] = tmp[i];
	rest[++j] = 0;
}

char	*before_nl(char *tmp)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = -1;
	if (!tmp)
		return (0);
	while (tmp[++i])
		if (tmp[i] == '\n')
			break ;
	i++;
	new = malloc(i + 1);
	if (!new)
		return (0);
	while (++j < i)
	{
		new[j] = tmp[j];
	}
	new[j] = 0;
	free(tmp);
	return (new);
}