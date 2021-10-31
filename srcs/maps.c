/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:58:53 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/31 14:03:14 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_x_y(t_var *var, char **argv)
{
	int		fd;
	char	*line;

	var->map.size.x = 0;
	var->map.size.y = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Map not found 1");
	while (ft_gnl(fd, &line))
	{
		var->map.size.x = strlen(line);
		var->map.size.y++;
		free(line);
	}
	var->map.size.y++;
	free(line);
	close(fd);
	return (0);
}

int	get_map(t_var *var, char **argv)
{
	int		row;
	int		fd;
	char	*line;

	row = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Map not found 2");
	while (ft_gnl(fd, &line))
	{
		var->map.mtx[row] = line;
		row++;
		free(line);
	}
	var->map.mtx[row] = line;
	free(line);	
	close(fd);
	return (0);
}

int	print_square(t_var var, int col, int row)
{
	if (var.map.mtx[row][col] == '1')
		mlx_put_image_to_window(var.mlx, var.win, var.tree.img_ptr,
			SPRITE_W * col, SPRITE_H * row);
	else if (var.map.mtx[row][col] == 'P')
		mlx_put_image_to_window(var.mlx, var.win, var.spt.img_ptr,
			SPRITE_W * col, SPRITE_H * row);
	else if (var.map.mtx[row][col] == 'C')
		mlx_put_image_to_window(var.mlx, var.win, var.collectible.img_ptr,
			SPRITE_W * col, SPRITE_H * row);
	else if (var.map.mtx[row][col] == 'E')
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
	var.spt.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/sprite.xpm",
			&var.spt.size.x, &var.spt.size.y);
	var.exit.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/exit.xpm",
			&var.exit.size.x, &var.exit.size.y);
	var.collectible.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/collec.xpm",
			&var.collectible.size.x, &var.collectible.size.y);
	print_map(var);
	return (0);
}
