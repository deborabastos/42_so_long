/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:37:31 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/25 22:19:50 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int get_init_position(t_var *var)
{
	int		row;
	int		col;

	row = 0;	
	while (row < var->map.size.y)
	{
		col = 0;
		while (col <= var->map.size.x)
		{
			if (var->map.map_mtx[row][col] == 'P')
			{
				var->sprite.position.x = col;
				var->sprite.position.y = row;				
				// printf("Col: %d\nRow: %d\n", var->sprite.position.x, var->sprite.position.y);
			}
			col++;
		}
		row++;
	}
	return (0);
}

// int render(t_var var)
// {
// 	int		row;
// 	int		col;

// 	var.map.map_mtx[var.sprite.position.y][var.sprite.position.x] = 0;

// 	return (0);
// }


int	key_press(int key, t_var *var)
{
	if (key == 53)
		exit(0);
	if ((key == LEFT_KEY || key == A_KEY) &&
		(var->map.map_mtx[var->sprite.position.y][var->sprite.position.x - 1] != '1'))
	{
		var->map.map_mtx[var->sprite.position.y][var->sprite.position.x] = '0';
		var->sprite.position.x -= 1;
		var->map.map_mtx[var->sprite.position.y][var->sprite.position.x] = 'P';
	}
	if ((key == RIGHT_KEY || key == D_KEY) &&
		(var->map.map_mtx[var->sprite.position.y][var->sprite.position.x + 1] != '1'))
	{
		var->map.map_mtx[var->sprite.position.y][var->sprite.position.x] = '0';
		var->sprite.position.x += 1;
		var->map.map_mtx[var->sprite.position.y][var->sprite.position.x] = 'P';
	}
	if ((key == DOWN_KEY || key == S_KEY) &&
		(var->map.map_mtx[var->sprite.position.y + 1][var->sprite.position.x] != '1'))
	{
		var->map.map_mtx[var->sprite.position.y][var->sprite.position.x] = '0';
		var->sprite.position.y += 1;
		var->map.map_mtx[var->sprite.position.y][var->sprite.position.x] = 'P';
	}
	if ((key == UP_KEY || key == W_KEY) &&
		(var->map.map_mtx[var->sprite.position.y - 1][var->sprite.position.x] != '1'))
	{
		var->map.map_mtx[var->sprite.position.y][var->sprite.position.x] = '0';
		var->sprite.position.y -= 1;
		var->map.map_mtx[var->sprite.position.y][var->sprite.position.x] = 'P';
	}

	// printf("-----------------\n");
	// int row = 0;
	// while(row < var->map.size.y)
	// {
	// 	printf("%s\n", var->map.map_mtx[row]);
	// 	row++; 
	// }

	load_map(*var);
	return (0);}
