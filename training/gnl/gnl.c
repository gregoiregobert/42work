/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:01:52 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/04 12:22:30 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*gnl(int fd)
{
	char	rest[BUFFER_SIZE + 1];
	char	*buff;
	char	*tmp;
	
	tmp = 0;
	if (fd < 0 || read(fd, rest, 0) < 0);
		return (0);
	if (*rest)
	{
		tmp = ft_strdup(rest);
		if (!tmp)
			return (0);
	}
	
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	i = -1;
	if (!str)
		return (0);
	new = malloc(ft_strlen(str) + 1);
	if (!new)
		return (0);
	while (str[++i])
		new[i] = str[i];
	new[++i] = 0;
	return (new);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}