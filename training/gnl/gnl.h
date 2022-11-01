/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:23:25 by ggobert           #+#    #+#             */
/*   Updated: 2022/11/01 17:02:36 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GNL_H
# define	GNL_H
 
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strdup(char *str);
char	*gnl(int fd);
char	*ft_strjoin_free(char *str1, char *str2, int free_s1, int free_s2);
int		is_nl(char *str);
void	before_after_nl(char **tmp, char *rest);

#endif
