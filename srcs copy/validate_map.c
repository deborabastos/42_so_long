/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:45:38 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/28 18:38:14 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls(t_var var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var.map.size.y)
	{
		col = 0;
		if (row == 0 || row == (var.map.size.y - 1))
		{
			while (var.map.mtx[row][col])
			{
				if (var.map.mtx[row][col] != '1')
					error("Invalid map: top or down wall not configured");
				col++;
			}
		}
		if (var.map.mtx[row][0] != '1'
			|| var.map.mtx[row][var.map.size.x - 1] != '1')
			error("Invalid map: lateral wall not configured");
		row++;
	}
	return (0);
}

int	check_sprites(t_var var)
{
	int		has[3];
	int		row;
	int		col;

	row = 0;
	while (row < var.map.size.y)
	{
		col = 0;
		while (col <= var.map.size.x)
		{
			if (var.map.mtx[row][col] == 'P')
				has[0] = 1;
			if (var.map.mtx[row][col] == 'E')
				has[1] = 1;
			if (var.map.mtx[row][col] == 'C')
				has[2] = 1;
			col++;
		}
		row++;
	}
	if (has[0] != 1 || has[1] != 1 || has[2] != 1)
		error("Invalid map: misssing PEC");
	return (0);
}

int	check_ret(t_var var)
{
	int		row;

	row = 0;
	while (row < var.map.size.y)
	{
		if (var.map.size.x != (int)strlen(var.map.mtx[row]))
			error("Invalid map: not a retangle");
		row++;
	}
	return (0);
}

int	check_char(t_var var)
{
	int		row;
	int		col;	

	row = 0;
	while (row < var.map.size.y)
	{
		col = 0;
		while (var.map.mtx[row][col])
		{
			if (var.map.mtx[row][col] != '0' && var.map.mtx[row][col] != '1'
				&& var.map.mtx[row][col] != 'P' && var.map.mtx[row][col] != 'E'
				&& var.map.mtx[row][col] != 'C')
				error("Invalid map: char not permited");
			col++;
		}
		row++;
	}
	return (0);
}

int	check_map(t_var var)
{
	check_walls(var);
	check_sprites(var);
	check_ret(var);
	check_char(var);
	return (0);
}
