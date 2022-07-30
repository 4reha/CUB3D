/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:17:25 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/30 17:22:50 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H
#define  SIZE_ 50
#define  SIZE_PLYR 20


#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

typedef struct	s_ray {
	float	end_x;
	float 	end_y;
	float	dx;
	float 	dy;
	float	distance;
}	t_ray;

typedef struct	s_point {
	int	x;
	int	y;
}	t_point;

typedef struct	s_player {
	float	x;
	float	y;
	int	turndirection;
	int	walkdirection;
	int	sidedirection;
	float rotatedirection;
	float rotatespeed;
	float walkspeed;
	t_ray	ray;
}	t_player;


typedef struct	s_info {
	t_point	*walls;
	int		blocks;
}	t_info;

typedef struct	s_data {
	void	*mlx;
	void	*wind;
	void	*img;
	void	*map_gb;
	void	*player_img;
	void	*map_wall;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		row;
	int		col;
	char	**map;
	int 	x;
	int 	y;
	t_info	info;
	t_player player;
}	t_data;

void	read_map(t_data *data);
void	initial(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		is_player(char c);
void	update_player(t_data *data);
void	background(t_data *data);
void	re_background(t_data *data);
void	save_walls_position(t_data *data);
// void put_block(t_data *data, int color);
// void re_draw(t_data *data);
// void draw_map(t_data *data);
// void put_player(t_data *data);
// void update_draw(t_data *data);
// void put_player2(t_data *data);
#endif
