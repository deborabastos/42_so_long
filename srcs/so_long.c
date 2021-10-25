/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/25 20:13:52 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(void)
{
	t_var	var;

	get_map(&var);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, var.map.size.x * SPRITE_W, var.map.size.y
			* SPRITE_H, "So long");
	check_map(var);
	load_map(var);
	mlx_hook(var.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &var);
	mlx_hook(var.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &var);
	mlx_loop(var.mlx);
}
