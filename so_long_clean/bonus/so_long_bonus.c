/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/12 17:46:53 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	init(t_var *var)
{
	var->map.mtx = malloc((var->map.size.y + 1) * sizeof(char *));
	var->map.mtx[var->map.size.y] = NULL;
	var->game.count_steps = 0;
	var->game.count_enemy = 0;
	var->enemy.pos.x = 0;
	var->enemy.pos.y = 0;
	var->has_enemy = 0;
	var->img.spt_path = "./img/sprite.xpm";
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

int	ft_expose(t_var *var)
{
	print_map(*var);
	print_steps(var);
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
	get_init_position(&var);
	check_enemy(&var);
	count_collec(&var);
	print_map(var);
	mlx_hook(var.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &var);
	mlx_hook(var.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &var);
	mlx_expose_hook(var.win, ft_expose, &var);
	if (var.has_enemy > 0)
		mlx_loop_hook(var.mlx, enemy_patrol, &var);
	mlx_loop(var.mlx);
}
