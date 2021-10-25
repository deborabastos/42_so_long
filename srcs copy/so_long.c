/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/25 16:10:51 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(void)
{
	t_var	var;

	// var.map.size.x = 0;
	// var.map.size.y = 0;

	// get_map(var);
	var.mlx = mlx_init();
	var.map.size.x = get_map_x(var);
	var.map.size.y = get_map_y(var);
	var.win = mlx_new_window(var.mlx, var.map.size.x * SPRITE_W, var.map.size.y
			* SPRITE_H, "So long");
	check_map(var);
	load_map(var);
	mlx_hook(var.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &var);
	mlx_hook(var.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &var);
	mlx_loop(var.mlx);
}