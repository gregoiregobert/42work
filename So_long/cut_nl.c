/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_nl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:18:14 by ggobert           #+#    #+#             */
/*   Updated: 2022/07/21 13:29:28 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*cut_nl(char *s)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = -1;
	while (s[i] != '\n' && s[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (0);
	while (++j < i)
		new[j] = s[j];
	new[j] = 0;
	free(s);
	return (new);
}
