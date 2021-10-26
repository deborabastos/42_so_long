/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:58:53 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/25 21:14:36 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_map(t_var *var)
{
	int		row;
	int		fd;
	char	*line;

	row = 0;
	fd = open(PATH_MAP, O_RDONLY);
	if (fd == -1)
		error("Map error");
	while (ft_gnl(fd, &line))
	{
		var->map.size.x = strlen(line);
		var->map.size.y++;
		var->map.map_mtx[row] = line;
		row++;
	}
	var->map.map_mtx[row] = line;	
	var->map.size.y++;
	close(fd);
	return (0);
}

int	print_square(t_var var, int col, int row)
{
	if (var.map.map_mtx[row][col] == '1')
		mlx_put_image_to_window(var.mlx, var.win, var.tree.img_ptr,
			SPRITE_W * col, SPRITE_H * row);
	else if (var.map.map_mtx[row][col] == 'P')
		mlx_put_image_to_window(var.mlx, var.win, var.sprite.img_ptr,
			SPRITE_W * col, SPRITE_H * row);
	else if (var.map.map_mtx[row][col] == 'C')
		mlx_put_image_to_window(var.mlx, var.win, var.collectible.img_ptr,
			SPRITE_W * col, SPRITE_H * row);
	else if (var.map.map_mtx[row][col] == 'E')
		mlx_put_image_to_window(var.mlx, var.win, var.exit.img_ptr,
			SPRITE_W * col, SPRITE_H * row);
	else
		mlx_put_image_to_window(var.mlx, var.win, var.floor.img_ptr,
			SPRITE_W * col, SPRITE_H * row);
	return (0);
}

int	print_map(t_var var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var.map.size.y)
	{
		col = 0;
		while (col < var.map.size.x)
		{
			print_square(var, col, row);
			col++;
		}
		row++;
	}
	return (0);
}

int	load_map(t_var var)
{
	var.floor.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/floor.xpm",
			&var.floor.size.x, &var.floor.size.y);
	var.tree.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/tree.xpm",
			&var.tree.size.x, &var.tree.size.y);
	var.sprite.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/sprite.xpm",
			&var.sprite.size.x, &var.sprite.size.y);
	var.exit.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/exit.xpm",
			&var.exit.size.x, &var.exit.size.y);
	var.collectible.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/collec.xpm",
			&var.collectible.size.x, &var.collectible.size.y);
	print_map(var);
	return (0);
}
