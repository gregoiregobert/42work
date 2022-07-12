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
# include "minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_imag
{
	void	*img;
	char	*addr;
	int 	bpp;
	int 	line_len;
	int 	endian;
}	t_imag;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char 	**map;
	t_imag	grass;
	t_imag	bee;
	t_imag	flower;
	t_imag	bush;
	t_imag	hive;
	int		width_window;
	int		height_window;
}	t_data;

int		handle_keypress(int keysym, t_data *data);
int		render(t_data *data);
int		dimension_rect(char **av, t_data *data);
int		rect_check(t_data *data);
int		wall_check(t_data *data);
int		item_position_out_check(t_data *data);
void	render_background(t_data *data, int color);
void	initialize(t_data *data);
void	free_map(t_data *data);
void	parsing(char **av, t_data *data);
void	pars_manager(char **av, t_data *data);
void	msg_err_1(t_data *data);
void	msg_err_2(t_data *data);
void	msg_err_3(t_data *data);
void	msg_err_4(t_data *data);

#endif

