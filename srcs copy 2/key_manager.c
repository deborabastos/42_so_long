/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:23:46 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/28 18:16:38 by dalves-p         ###   ########.fr       */
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
	if (key == 53)
		exit(0);
	else
		movements(key, var);
	if (init_steps != var->game.count_steps)
		printf("Steps: %d\n", var->game.count_steps);
	load_map(*var);
	return (0);
}
