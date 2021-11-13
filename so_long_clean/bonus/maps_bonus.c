/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:58:53 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/12 17:46:45 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	get_x_y(t_var *var, char **argv)
{
	int		fd;
	char	*line;

	var->map.size.x = 0;
	var->map.size.y = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Map not found");
	while (ft_gnl(fd, &line))
	{
		var->map.size.x = ft_strlen(line);
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

	row = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Map not found");
	while (ft_gnl(fd, &var->map.mtx[row]))
		row++;
	close(fd);
	check_map(*var);
	return (0);
}

int	load_map(t_var var, int row, int col)
{
	if (var.map.mtx[row][col] == '1')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/tree.xpm",
				&var.img.size.x, &var.img.size.y);
	else if (var.map.mtx[row][col] == '0')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/floor.xpm",
				&var.img.size.x, &var.img.size.y);
	else if (var.map.mtx[row][col] == 'E')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/exit.xpm",
				&var.img.size.x, &var.img.size.y);
	else if (var.map.mtx[row][col] == 'C')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/collec.xpm",
				&var.img.size.x, &var.img.size.y);
	else if (var.map.mtx[row][col] == 'P')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, var.img.spt_path,
				&var.img.size.x, &var.img.size.y);
	else if (var.map.mtx[row][col] == 'Y' && var.has_enemy > 0)
		enemy_animation(&var);
	mlx_put_image_to_window(var.mlx, var.win, var.img.img_ptr, SPRITE_W * col,
		SPRITE_H * row);
	mlx_destroy_image(var.mlx, var.img.img_ptr);
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
			load_map(var, row, col);
			col++;
		}
		row++;
	}
	return (0);
}
