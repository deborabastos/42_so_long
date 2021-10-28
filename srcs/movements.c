/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:37:31 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/28 18:16:22 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_left(t_var *var)
{
	var->map.map_mtx[var->spt.pos.y][var->spt.pos.x] = '0';
	var->spt.pos.x -= 1;
	var->map.map_mtx[var->spt.pos.y][var->spt.pos.x] = 'P';
	var->game.count_steps++;
	return (0);
}

int	move_right(t_var *var)
{
	var->map.map_mtx[var->spt.pos.y][var->spt.pos.x] = '0';
	var->spt.pos.x += 1;
	var->map.map_mtx[var->spt.pos.y][var->spt.pos.x] = 'P';
	var->game.count_steps++;
	return (0);
}

int	move_down(t_var *var)
{
	var->map.map_mtx[var->spt.pos.y][var->spt.pos.x] = '0';
	var->spt.pos.y += 1;
	var->map.map_mtx[var->spt.pos.y][var->spt.pos.x] = 'P';
	var->game.count_steps++;
	return (0);
}

int	move_up(t_var *var)
{
	var->map.map_mtx[var->spt.pos.y][var->spt.pos.x] = '0';
	var->spt.pos.y -= 1;
	var->map.map_mtx[var->spt.pos.y][var->spt.pos.x] = 'P';
	var->game.count_steps++;
	return (0);
}

int	movements(int key, t_var *var)
{
	if ((key == LEFT_KEY || key == A_KEY)
		&& (var->map.map_mtx[var->spt.pos.y][var->spt.pos.x - 1] == 'E'))
		check_collect(var);
	else if ((key == LEFT_KEY || key == A_KEY)
		&& (var->map.map_mtx[var->spt.pos.y][var->spt.pos.x - 1] != '1'))
		move_left(var);
	if ((key == RIGHT_KEY || key == D_KEY)
		&& (var->map.map_mtx[var->spt.pos.y][var->spt.pos.x + 1] == 'E'))
		check_collect(var);
	else if ((key == RIGHT_KEY || key == D_KEY)
		&& (var->map.map_mtx[var->spt.pos.y][var->spt.pos.x + 1] != '1'))
		move_right(var);
	if ((key == DOWN_KEY || key == S_KEY)
		&& (var->map.map_mtx[var->spt.pos.y + 1][var->spt.pos.x] == 'E'))
		check_collect(var);
	else if ((key == DOWN_KEY || key == S_KEY)
		&& (var->map.map_mtx[var->spt.pos.y + 1][var->spt.pos.x] != '1'))
		move_down(var);
	if ((key == UP_KEY || key == W_KEY)
		&& (var->map.map_mtx[var->spt.pos.y - 1][var->spt.pos.x] == 'E'))
		check_collect(var);
	else if ((key == UP_KEY || key == W_KEY)
		&& (var->map.map_mtx[var->spt.pos.y - 1][var->spt.pos.x] != '1'))
		move_up(var);
	return (0);
}
