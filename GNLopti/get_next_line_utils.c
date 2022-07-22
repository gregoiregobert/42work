/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:48:44 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/22 14:17:57 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i++])
		len++;
	return (len);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*new_str;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (0);
	while (s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = 0;
	free(s1);
	return (new_str);
}

char	*ft_strdup(char *str)
{
	int		len;
	int		i;
	char	*new;

	i = 0;
	len = ft_strlen(str);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	while (len--)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*cut_at(char *str, int n)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (n + 1));
	if (!new)
		return (0);
	while (i < n)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	free(str);
	return (new);
}

char	*after_line(char *str, char *stat, int n)
{
	int		i;
	int		j;

	j = 0;
	i = n;
	if (!n)
		return (stat);
	while (str[i])
		stat[j++] = str[i++];
	stat[j] = 0;
	return (stat);
}
