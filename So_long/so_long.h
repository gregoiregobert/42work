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

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}		t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, void *data);
int		render(t_data *data);
int 	render_rect(t_data *data, t_rect rect);
void	render_background(t_data *data, int color);
void	img_pixel_put(t_data *data, int x, int y, int color);

#endif

