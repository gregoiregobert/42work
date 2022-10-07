/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:50:38 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/07 15:02:47 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	while (*str++)
		l++;
	return (l);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	str_isdigit(char *str)
{
	int	i;
	
	i = -1;
	while (str[++i])	
		if (ft_isdigit(str[i]) == 0 && str[i] != '-')
			return (0);
	return (1);
			
}

int	ft_atoi(const char *str)
{
	int	pos;
	int	ret;

	pos = 1;
	ret = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			pos *= -1;
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + (*str++ - '0');
	return (ret * pos);
}
