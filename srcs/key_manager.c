/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:23:46 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/04 18:18:11 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mlx_close(t_var *var)
{
	free_map(var);
	exit(0);
}

int	key_press(int key, t_var *var)
{
	int	init_steps;

	init_steps = var->game.count_steps;
	if (key == ESC)
	{
		free_map(var);
		exit(0);
	}
	else
	{		
		enemy(key, var);
		movements(key, var);
	}
	if (init_steps != var->game.count_steps)
		printf("Steps: %d\n", var->game.count_steps);
	print_map(*var);
	print_steps(var);
	return (0);
}
