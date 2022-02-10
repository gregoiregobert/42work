/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:32:09 by ggobert           #+#    #+#             */
/*   Updated: 2022/02/07 17:47:51 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int		ft_nl(char *ret);
int		ft_n_nl(char *ret);
int		ft_strlen(char *str);
char	*ft_read(char *show, int fd);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*cut_at(char *str, int n);
char	*after_line(char *str, char *ret, int n);

# endif
