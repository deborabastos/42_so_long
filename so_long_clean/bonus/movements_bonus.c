/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:37:31 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/12 17:46:49 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	move_left(t_var *var)
{
	var->map.mtx[var->img.pos.y][var->img.pos.x] = '0';
	var->img.pos.x -= 1;
	var->map.mtx[var->img.pos.y][var->img.pos.x] = 'P';
	var->game.count_steps++;
	var->img.spt_path = "./img/sprite2.xpm";
	return (0);
}

int	move_right(t_var *var)
{
	var->map.mtx[var->img.pos.y][var->img.pos.x] = '0';
	var->img.pos.x += 1;
	var->map.mtx[var->img.pos.y][var->img.pos.x] = 'P';
	var->game.count_steps++;
	var->img.spt_path = "./img/sprite1.xpm";
	return (0);
}

int	move_down(t_var *var)
{
	var->map.mtx[var->img.pos.y][var->img.pos.x] = '0';
	var->img.pos.y += 1;
	var->map.mtx[var->img.pos.y][var->img.pos.x] = 'P';
	var->game.count_steps++;
	return (0);
}

int	move_up(t_var *var)
{
	var->map.mtx[var->img.pos.y][var->img.pos.x] = '0';
	var->img.pos.y -= 1;
	var->map.mtx[var->img.pos.y][var->img.pos.x] = 'P';
	var->game.count_steps++;
	return (0);
}

int	movements(int key, t_var *var)
{
	if ((key == A_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x - 1] == 'E'))
		check_collect(var);
	else if ((key == A_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x - 1] != '1'))
		move_left(var);
	if ((key == D_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x + 1] == 'E'))
		check_collect(var);
	else if ((key == D_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x + 1] != '1'))
		move_right(var);
	if ((key == S_KEY)
		&& (var->map.mtx[var->img.pos.y + 1][var->img.pos.x] == 'E'))
		check_collect(var);
	else if ((key == S_KEY)
		&& (var->map.mtx[var->img.pos.y + 1][var->img.pos.x] != '1'))
		move_down(var);
	if ((key == W_KEY)
		&& (var->map.mtx[var->img.pos.y - 1][var->img.pos.x] == 'E'))
		check_collect(var);
	else if ((key == W_KEY)
		&& (var->map.mtx[var->img.pos.y - 1][var->img.pos.x] != '1'))
		move_up(var);
	return (0);
}
