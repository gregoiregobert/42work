/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:10:32 by ggobert           #+#    #+#             */
/*   Updated: 2022/01/27 17:55:47 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin_g(char *s1, char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen_g(s1) + ft_strlen_g(s2);
	ret = malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	while (s1[i])
		ret[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[j++] = s2[i++];
	ret[j] = 0;
	free(s1);
	return (ret);
}

char	*ft_strnback(char *s, size_t n)
{
	int		i;
	int		j;
	char	*new;

	if (!s)
		return (0);
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen_g(s) - n + 1));
	if (!new)
		return (0);
	i = n;
	while (s[i])
	{
		new[j++] = s[i++];
	}
	new[j] = 0;
	free(s);
	return (new);
}