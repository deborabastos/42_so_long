/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:58:53 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/25 14:44:49 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_map_x(t_var var)
{
	int		fd;
	char	*line;

	fd = open(PATH_MAP, O_RDONLY);
	if (fd == -1)
		error("Map error");
	while (ft_gnl(fd, &line) > 0)
		var.map.size.x = strlen(line);
	close(fd);
	return (var.map.size.x);
}

int	get_map_y(t_var var)
{
	int		fd;
	char	*line;

	fd = open(PATH_MAP, O_RDONLY);
	if (fd == -1)
		error("Map error");
	var.map.size.y = 0;
	while (ft_gnl(fd, &line) > 0)
		var.map.size.y++;
	var.map.size.y++;
	close(fd);
	return (var.map.size.y);
}

int	print_sprite(t_var var, char *line, int col, int row)
{
	if (line[col] == '1')
		mlx_put_image_to_window(var.mlx, var.win, var.tree.img_ptr,
			SPRITE_W * col, SPRITE_H * row);
	else if (line[col] == 'P')
		mlx_put_image_to_window(var.mlx, var.win, var.sprite.img_ptr,
			SPRITE_W * col, SPRITE_H * row);
	else if (line[col] == 'C')
		mlx_put_image_to_window(var.mlx, var.win, var.collectible.img_ptr,
			SPRITE_W * col, SPRITE_H * row);
	else if (line[col] == 'E')
		mlx_put_image_to_window(var.mlx, var.win, var.exit.img_ptr,
			SPRITE_W * col, SPRITE_H * row);
	else
		mlx_put_image_to_window(var.mlx, var.win, var.floor.img_ptr,
			SPRITE_W * col, SPRITE_H * row);
	return (0);
}

int	print_map(t_var var, int fd)
{
	int		col;
	int		row;
	char	*line;

	row = 0;
	while ((ft_gnl(fd, &line) >= 0) && row < ROWS)
	{
		col = 0;
		while (col < var.map.size.x)
		{
			print_sprite(var, line, col, row);
			col++;
		}
		free(line);
		row++;
	}
	free(line);
	return (0);
}

int	load_map(t_var var)
{
	int		fd;

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
	fd = open(PATH_MAP, O_RDONLY);
	print_map(var, fd);
	close(fd);
	return (0);
}
