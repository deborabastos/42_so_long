/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:37:31 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/09 14:02:53 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	enemy_move_right(t_var *var)
{
	if (var->map.mtx[var->enemy.pos.y][var->enemy.pos.x + 1] == 'P')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST 1 !!!!\e[0m\n");
	var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = '0';
	var->enemy.pos.x += 1;
	var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = 'Y';
	var->game.count_enemy++;
	return (0);
}

int	enemy_move_down(t_var *var)
{
	if (var->map.mtx[var->enemy.pos.y + 1][var->enemy.pos.x] == 'P')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST 2 !!!!\e[0m\n");
	var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = '0';
	var->enemy.pos.y += 1;
	var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = 'Y';
	var->game.count_enemy++;
	return (0);
}

int	enemy_move_left(t_var *var)
{
	if (var->map.mtx[var->enemy.pos.y][var->enemy.pos.x - 1] == 'P')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST 3 !!!!\e[0m\n");
	var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = '0';
	var->enemy.pos.x -= 1;
	var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = 'Y';
	var->game.count_enemy++;
	return (0);
}

int	enemy_move_up(t_var *var)
{
	if (var->map.mtx[var->enemy.pos.y - 1][var->enemy.pos.x] == 'P')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST 4 !!!!\e[0m\n");
	var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = '0';
	var->enemy.pos.y -= 1;
	var->map.mtx[var->enemy.pos.y][var->enemy.pos.x] = 'Y';
	var->game.count_enemy++;
	return (0);
}

int	enemy_patrol(t_var *var)
{
	get_enemy_position(var);
	usleep(200000);
	if ((var->map.mtx[var->enemy.pos.y][var->enemy.pos.x + 1] == '0'
		|| var->map.mtx[var->enemy.pos.y][var->enemy.pos.x + 1] == 'P')
		&& var->game.count_enemy < var->map.size.x)
		enemy_move_right(var);
	else if ((var->map.mtx[var->enemy.pos.y + 1][var->enemy.pos.x] == '0'
		|| var->map.mtx[var->enemy.pos.y + 1][var->enemy.pos.x] == 'P')
		&& var->game.count_enemy < (var->map.size.x + var->map.size.y))
		enemy_move_down(var);
	else if ((var->map.mtx[var->enemy.pos.y][var->enemy.pos.x - 1] == '0'
		|| var->map.mtx[var->enemy.pos.y][var->enemy.pos.x - 1] == 'P')
		&& var->game.count_enemy < ((2 * var->map.size.x) + var->map.size.y))
		enemy_move_left(var);
	else if ((var->map.mtx[var->enemy.pos.y - 1][var->enemy.pos.x] == '0'
		|| var->map.mtx[var->enemy.pos.y - 1][var->enemy.pos.x] == 'P')
		&& var->game.count_enemy < (2 * (var->map.size.x + var->map.size.y)))
		enemy_move_up(var);
	else
		var->game.count_enemy = 0;
	print_map(*var);
	print_steps(var);
	return (0);
}
