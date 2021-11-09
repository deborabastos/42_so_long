/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:23:46 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/09 15:32:47 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mlx_close(t_var *var)
{
	free_exit(var, "\e[33m\e[1mGame closed! (X)\e[0m\n");
	return (0);
}

int	key_press(int key, t_var *var)
{
	int	init_steps;

	init_steps = var->game.count_steps;
	if (key == ESC)
	{
		free_exit(var, "\e[33m\e[1mGame closed! (ESC)\e[0m\n");
	}
	else
	{
		movements(key, var);
		if (var->has_enemy > 0)
			step_into_enemy(key, var);
	}
	if (init_steps != var->game.count_steps)
		printf("Steps: %d\n", var->game.count_steps);
	print_map(*var);
	print_steps(var);
	return (0);
}
