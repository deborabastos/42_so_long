/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:45:38 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/20 22:52:50 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls(t_var var)
{
	int		fd;
	int		row;
	int		col;
	char	*line;

	row = 0;
	fd = open(PATH_MAP, O_RDONLY);
	while ((ft_gnl(fd, &line) >= 0) && (row < var.map.size.y))
	{
		col = 0;
		if (row == 0 || row == (var.map.size.y - 1))
		{
			while (line[col])
			{
				if (line[col] != '1')
					error("Invalid map: top or down wall not configured");
				col++;
			}
		}
		if (line[0] != '1' || line[var.map.size.x - 1] != '1')
			error("Invalid map: lateral wall not configured");
		row++;
	}
	close(fd);
	return (0);
}

int	check_sprites(t_var var)
{
	int		fd;
	int		has[3];
	int		col;
	char	*line;

	fd = open(PATH_MAP, O_RDONLY);
	while (ft_gnl(fd, &line) > 0)
	{
		col = 0;
		while (col <= var.map.size.x)
		{
			if (line[col] == 'P')
				has[0] = 1;
			if (line[col] == 'E')
				has[1] = 1;
			if (line[col] == 'C')
				has[2] = 1;
			col++;
		}
	}
	if (has[0] != 1 || has[1] != 1 || has[2] != 1)
		error("Invalid map: misssing PEC");
	close(fd);
	return (0);
}

int	check_ret(t_var var)
{
	int		fd;
	int		row;
	char	*line;

	row = 0;
	fd = open(PATH_MAP, O_RDONLY);
	while ((ft_gnl(fd, &line) >= 0) && (row < var.map.size.y))
	{
		if (var.map.size.x != (int)strlen(line))
			error("Invalid map: not a retangle");
		row++;
	}
	close(fd);
	return (0);	
}


int	check_char(void)
{
	int		fd;
	int		col;	
	char	*line;

	fd = open(PATH_MAP, O_RDONLY);
	while (ft_gnl(fd, &line))
	{
		col = 0;
		while (line[col])
		{
			if (line[col] != '0' && line[col] != '1' && line[col] != 'P'
				&& line[col] != 'E' && line[col] != 'C')
				error("Invalid map: char not permited");
			col++;
		}
	}
	close(fd);
	return (0);
}

int	check_map(t_var var)
{
	check_walls(var);
	check_sprites(var);
	check_ret(var);
	check_char();
	return (0);
}
