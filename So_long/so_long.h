/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <ggobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:05:48 by ggobert           #+#    #+#             */
/*   Updated: 2022/10/03 11:08:12 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_imag
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_imag;

typedef struct s_way
{
	int		c;
	int		e;
	char	*move;
	int		x;
	int		y;
}	t_way;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	**copy;
	t_imag	grass;
	t_imag	bee;
	t_imag	bee_r;
	t_imag	bee_l;
	t_imag	bee_d;
	t_imag	flower;
	t_imag	wall;
	t_imag	hive;
	t_imag	bee_flower;
	t_imag	bee_flower_r;
	t_imag	bee_flower_l;
	t_imag	bee_flower_d;
	t_imag	bee_hive;
	t_imag	bee_hive_r;
	t_imag	bee_hive_l;
	t_imag	bee_hive_d;
	int		width_window;
	int		height_window;
	int		move;
	int		item;
	int		position;
	int		out;
	t_pos	perso;
	t_way	way;
}	t_data;

int		find_way(t_data *data);
int		handle_cross(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		item_position_out_check(t_data *data);
int		no_c(t_data *data);
int		no_way(t_data *data);
int		open_fd(char **av);
int		rect_check(t_data *data);
int		symbole_check(t_data *data);
int		wall_check(t_data *data);
char	backtrack_move(t_data *data);
char	*cut_nl(char *s);
void	check_args(int ac, char **av);
void	destroy_img(t_data *data);
void	destroy_img_1(t_data *data);
void	dimension_rect(char **av, t_data *data);
void	dir_up(t_data *data);
void	dir_wall_up(t_data *data);
void	dir_down(t_data *data);
void	dir_wall_down(t_data *data);
void	dir_left(t_data *data);
void	dir_wall_left(t_data *data);
void	dir_right(t_data *data);
void	dir_wall_right(t_data *data);
void	display_map(t_data *data);
void	display_tile(t_data *data, int j, int i);
void	display_tile_flower(t_data *data, int j, int i);
void	display_tile_hive(t_data *data, int j, int i);
void	display_tile_bee(t_data *data, int j, int i);
void	exit_properly(t_data *data);
void	find_p(t_data *data);
void	img_protect(t_data *data);
void	init_img(t_data *data);
void	init_img_1(t_data *data);
void	init_img_2(t_data *data);
void	init_img_3(t_data *data);
void	init_move(t_data *data, char c);
void	initialize(t_data *data);
void	free_map(t_data *data);
void	map_copy(t_data *data);
void	map_manager(t_data *data);
void	msg_err_0(void);
void	msg_err_1(t_data *data);
void	msg_err_2(t_data *data);
void	msg_err_3(t_data *data);
void	msg_err_4(t_data *data);
void	msg_err_5(void);
void	msg_err_6(void);
void	msg_err_7(t_data *data);
void	msg_err_8(t_data *data);
void	new_move(t_data *data, char c);
void	pars_manager(int av, char **ac, t_data *data);
void	parsing(char **av, t_data *data);
void	perror_exit(void);
void	position_perso(t_data *data, int j, int i);
void	rm_lastmove(t_data *data);
void	test_down(t_data *data);
void	test_left(t_data *data);
void	test_right(t_data *data);
void	test_up(t_data *data);

#endif
