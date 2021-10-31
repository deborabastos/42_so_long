/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/31 14:41:16 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init(t_var *var)
{
	var->map.mtx = malloc(var->map.size.x * var->map.size.y * sizeof(int));
	var->game.count_steps = 0;
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2)
		error("Provide map name and extension as argument\n\
Ex: ./so_long maps/map.ber");
	if (argc > 2)
		error("Too many arguments. Provide only map name and extension\n\
Ex: ./so_long maps/map.ber");
	if (ft_strstr(argv[1], ".ber") == NULL)
		error("Invalid map extension. Use .ber");
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	var;

	check_args(argc, argv);
	get_x_y(&var, argv);
	init(&var);
	get_map(&var, argv);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, var.map.size.x * SPRITE_W, var.map.size.y
			* SPRITE_H, "So long");
	check_map(var);
	load_map(var);
	get_init_position(&var);
	count_collec(&var);
	mlx_hook(var.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &var);
	mlx_hook(var.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &var);
	mlx_loop(var.mlx);
	while (*var.map.mtx)
	{
		free(var.map.mtx);
		var.map.mtx++;
	}
	free(var.map.mtx);
}
