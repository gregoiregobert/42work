/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:12:57 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/01 17:09:19 by ggobert          ###   ########.fr       */
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
	buff = malloc(BUFFER_SIZE + 1);
	count = read(fd, buff, BUFFER_SIZE);
	printf("%s", buff);
	while (count == BUFFER_SIZE)
	{
		tmp = ft_strjoin_free(buff, tmp, 0, 1);
		if (is_nl(tmp))
			break;
	}
	before_after_nl(&tmp, rest);
	return (tmp);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	i = 0;
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
	if (str[i++])
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
	while (str1[i])
		i++;
	while (str2[i])
		i++;
	tmp = malloc(i + 1);
	i = -1;
	j = -1;
	while (str1[++i])
		tmp[++j] = str1[i];
	i = -1;
	while (str2[++i])
		tmp[++j] = str2[i];
	tmp[++j] = 0;
	if (free_s1)
		free(str1);
	if (free_s2)
		free(str2);
	return (tmp);
}

void	before_after_nl(char **tmp, char *rest)
{
	int		i;
	int 	j;
	int 	k;
	char	*ret;

	i = -1;
	k = 0;
	while (*tmp[++i])
		if (*tmp[i] == '\n')
			break ;
	j = i;
	while (*tmp[i++])
		rest[k++] = *tmp[i];
	ret = malloc(j + 1);
	if (!ret)
		return ;
	i = 0;
	while (i <= j)
		ret[i] = *tmp[i];
	ret[i] = 0;
	free(*tmp);
	*tmp = ret;
}
