/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:23:25 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/02 14:55:26 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GNL_H
# define	GNL_H
 
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*before_nl(char *tmp);
char	*ft_strdup(char *str);
char	*ft_strjoin_free(char *str1, char *str2, int free_s1, int free_s2);
char	*gnl(int fd);
int		is_nl(char *str);
void	after_nl(char *tmp, char *rest);

#endif
