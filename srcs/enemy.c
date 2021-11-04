/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:37:31 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/04 19:12:00 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	enemy(int key, t_var *var)
{
	if ((key == A_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x - 1] == 'Y'))
	{
		free_map(var);
		exit(0);
	}
	if ((key == D_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x + 1] == 'Y'))
	{
		free_map(var);
		exit(0);
	}
	if ((key == S_KEY)
		&& (var->map.mtx[var->img.pos.y + 1][var->img.pos.x] == 'Y'))
	{
		free_map(var);
		exit(0);
	}
	if ((key == W_KEY)
		&& (var->map.mtx[var->img.pos.y - 1][var->img.pos.x] == 'Y'))
	{
		free_map(var);
		exit(0);
	}
	return (0);
}
