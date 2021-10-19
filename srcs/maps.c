/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:58:53 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/19 15:08:44 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	print_map(t_var var, int fd, char *line)
{
	int		col;
	int		row;
	
	var.floor.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/floor.xpm", &var.floor.size.x, &var.floor.size.y);
	var.tree.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/tree.xpm", &var.tree.size.x, &var.tree.size.y);
	var.sprite.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/sprite.xpm", &var.sprite.size.x, &var.sprite.size.y);
	var.exit.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/exit.xpm", &var.exit.size.x, &var.exit.size.y);
	var.collectible.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/collectible.xpm", &var.collectible.size.x, &var.collectible.size.y);
	col = 0;
	row = 0;
	while (row < ROWS)
	{
		while (ft_gnl(fd, &line) > 0)
		{
			col = 0;
			while (col < COLUMNS)
			{
				if(line[col] == '1')
					mlx_put_image_to_window(var.mlx, var.win, var.tree.img_ptr, SPRITE_W * col, SPRITE_H * row);
				else if (line[col] == 'P')
					mlx_put_image_to_window(var.mlx, var.win, var.sprite.img_ptr, SPRITE_W * col, SPRITE_H * row);
				else if (line[col] == 'C')
					mlx_put_image_to_window(var.mlx, var.win, var.collectible.img_ptr, SPRITE_W * col, SPRITE_H * row);
				else if (line[col] == 'E')
					mlx_put_image_to_window(var.mlx, var.win, var.exit.img_ptr, SPRITE_W * col, SPRITE_H * row);
				else 
					mlx_put_image_to_window(var.mlx, var.win, var.floor.img_ptr, SPRITE_W * col, SPRITE_H * row);	
				col++;
			}
			free(line);
			row++;
		}		
		free(line);
	}
	return (0);
}

int get_map(t_var var)
{
	int		fd;
	char	*line;

	fd = open("./maps/map.ber", O_RDONLY);
	if (fd == -1)
		return (1);
	print_map(var, fd, line);
	return (0);
}
