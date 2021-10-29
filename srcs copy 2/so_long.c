/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/29 12:06:39 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	check_args(int argc, char **argv)
// {
// 	if (argc < 2)
// 		error("Provide map name and extension as argument\nEx: ./so_long m.ber");
// 	if (argc > 2)
// 		error("Too many arguments.\nEx: ./so_long map.ber");
// 	if (ft_strstr(argv[1], ".ber") == NULL)
// 		error("Invalid map extension. Use .ber");
// 	return (0);
// }

int	main(void)
{
	t_var	var;

	// var.map.mtx = malloc(5 * 3 * sizeof(char));
		
	// printf("argc: %d - argv[1]: %s\n", argc, argv[1]);
	get_map(&var);
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
}
