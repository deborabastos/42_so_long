/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:23:46 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/31 15:59:27 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mlx_close(void)
{
	exit(0);
}

int	key_press(int key, t_var *var)
{
	int	init_steps;

	init_steps = var->game.count_steps;
	if (key == ESC)
		exit(0);
	else
		movements(key, var);
	if (init_steps != var->game.count_steps)
		printf("Steps: %d\n", var->game.count_steps);
	load_map(*var);
	mlx_string_put(var->mlx, var->win, (var->spt.pos.x * SPRITE_W) + 10,
		(var->spt.pos.y * SPRITE_H) + 10, 0x833000,
		ft_itoa(var->game.count_steps));
	return (0);
}
