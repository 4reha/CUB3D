/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:17:25 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/28 10:46:06 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H
#define  SIZE_ 50
#define  ROW 5
#define  COL 5

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "gnl/get_next_line.h"
#include "libft/libft.h"

typedef struct	s_player {
	int	x;
	int	y;

	float	radius;
	float	turndirection;
	float	walkdirection;
	float movespeed;
	float rotatedirection;
	float rotatespeed;
	float walkspeed;
}	t_player;

typedef struct	s_data {
	void	*mlx;
	void	*wind;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		row;
	int		col;
	char	**map;
	int 	put_in_x;
	int 	put_in_y;
	t_player player;
}	t_data;

void	read_map(t_data *data);
void	initial(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		is_player(char c);
// void put_block(t_data *data, int color);
// void re_draw(t_data *data);
// void draw_map(t_data *data);
// void put_player(t_data *data);
// void update_draw(t_data *data);
// void put_player2(t_data *data);
#endif
