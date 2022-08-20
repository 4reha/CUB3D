/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:12:35 by obelkhad          #+#    #+#             */
/*   Updated: 2022/08/20 09:46:36 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	read_map(t_data *data)
{
	int		fd;
	char	*line;
	char	*tmp_map;

	fd = open(data->mapath, O_RDONLY);
	if (fd == -1)
		ft_error(data, "The scene description file connot be found");
	data->mapLen = 0;
	line = get_next_line(fd);
	tmp_map = NULL;
	while (line)
	{
		map_parsing(data, line, &tmp_map, fd);
		if (tmp_map)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	data->map = ft_split(tmp_map, '\n');
	free(tmp_map);
	check_walls(data);
}

void	start_connection(t_data *data)
{
	data->mlx = mlx_init();
	data->wind = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cube3D");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	initial(t_data *data)
{
	data->player.turndirection = 0;
	data->player.walkdirection = 0;
	data->player.sidedirection = 0;
	data->player.rotatespeed = ROTATE_SPEED;
	data->player.walkspeed = WALK_SPEED;
	data->row = 0;
	data->col = 0;
	data->texture.NO = NULL;
	data->texture.SO = NULL;
	data->texture.WE = NULL;
	data->texture.EA = NULL;
	data->texture.F = 0;
	data->texture.C = 0;
	data->map = NULL;
	read_map(data);
	start_connection(data);
	data->texture.wall_NO = mlx_xpm_file_to_image(data->mlx, data->texture.NO,
			&data->texture.no_w, &data->texture.no_h);
	data->texture.wall_SO = mlx_xpm_file_to_image(data->mlx, data->texture.SO,
			&data->texture.so_w, &data->texture.so_h);
	data->texture.wall_EA = mlx_xpm_file_to_image(data->mlx, data->texture.WE,
			&data->texture.ea_w, &data->texture.ea_h);
	data->texture.wall_WE = mlx_xpm_file_to_image(data->mlx, data->texture.EA,
			&data->texture.we_w, &data->texture.we_h);
	data->texture.Door = mlx_xpm_file_to_image(data->mlx, "images/door.xpm",
			&data->texture.door_w, &data->texture.door_h);
}

void	get_info(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (data->map[++j])
	{
		i = 0;
		while (data->map[j][i] && data->map[j][i] != '\n')
		{
			if (is_player(data->map[j][i]))
			{
				data->player.x = i;
				data->player.y = j;
				data->player.h_x = data->player.x * SIZE_ + SIZE_PLYR / 2;
				data->player.h_y = data->player.y * SIZE_ + SIZE_PLYR / 2;
				data->player.v_x = data->player.x * SIZE_ + SIZE_PLYR / 2;
				data->player.v_y = data->player.y * SIZE_ + SIZE_PLYR / 2;
				if (data->map[j][i] == 'N')
					data->player.rotatedirection = M_PI_2;
				if (data->map[j][i] == 'E')
					data->player.rotatedirection = 0;
				if (data->map[j][i] == 'S')
					data->player.rotatedirection = 3 * M_PI_2;
				if (data->map[j][i] == 'W')
					data->player.rotatedirection = M_PI;
			}
			i++;
		}
	}
}
