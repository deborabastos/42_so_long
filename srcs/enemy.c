/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:37:31 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/08 17:39:51 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_enemy_position(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var->map.size.y)
	{
		col = 0;
		while (col <= var->map.size.x)
		{
			if (var->map.mtx[row][col] == 'Y')
			{
				var->enemy.pos.x = col;
				var->enemy.pos.y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	enemy(int key, t_var *var)
{
	if ((key == A_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x - 1] == 'Y'))
	{
		printf("\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
		free_exit(var);
	}
	if ((key == D_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x + 1] == 'Y'))
	{
		printf("\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
		free_exit(var);
	}
	if ((key == S_KEY)
		&& (var->map.mtx[var->img.pos.y + 1][var->img.pos.x] == 'Y'))
	{
		printf("\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
		free_exit(var);
	}
	if ((key == W_KEY)
		&& (var->map.mtx[var->img.pos.y - 1][var->img.pos.x] == 'Y'))
	{
		printf("\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
		free_exit(var);
	}
	return (0);
}

int	enemy_patrol(t_var *var)
{
	get_enemy_position(var);
	usleep(50000);
	if (var->map.mtx[var->enemy.pos.y][var->enemy.pos.x + 1] == '0' &&
		var->game.count_enemy < var->map.size.x)
	{
		var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = '0';
		var->enemy.pos.x += 1;
		var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = 'Y';
		var->game.count_enemy++;
	}
	else if (var->map.mtx[var->enemy.pos.y + 1][var->enemy.pos.x] == '0' &&
		var->game.count_enemy < (var->map.size.x + var->map.size.y))
	{
		var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = '0';
		var->enemy.pos.y += 1;
		var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = 'Y';
		var->game.count_enemy++;
	}
	else if (var->map.mtx[var->enemy.pos.y][var->enemy.pos.x - 1] == '0' &&
		var->game.count_enemy < ((2 * var->map.size.x) + var->map.size.y))
	{
		var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = '0';
		var->enemy.pos.x -= 1;
		var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = 'Y';
		var->game.count_enemy++;
	}
	else if (var->map.mtx[var->enemy.pos.y - 1][var->enemy.pos.x] == '0' &&
		var->game.count_enemy < (2 * (var->map.size.x + var->map.size.y)))
	{
		var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = '0';
		var->enemy.pos.y -= 1;
		var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = 'Y';
		var->game.count_enemy++;
	}
	else
		var->game.count_enemy = 0;
	print_map(*var);
	print_steps(var);
	return (0);
}
