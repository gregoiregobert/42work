/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:05:48 by ggobert           #+#    #+#             */
/*   Updated: 2022/06/23 13:23:12 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <X11/X.h>

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}		t_data;

#endif

