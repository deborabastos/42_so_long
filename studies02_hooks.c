/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   studies_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/09/27 19:23:09 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

// Print the keycode of the key pressed
int	key_hook(int keycode, t_vars *vars)
{
	printf("Keycode: %d\n", keycode);
}

// Print button code and the coordinates where click was pressed
int mouse_hook(int button, int x, int y, t_vars *var)
{
	printf("Mouse pressed\nButton: %d \nCoordinates x: %d, y: %d\n", button, x, y);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	printf("-------------------------------\n");
	printf("Press key to print keycode\n");
	printf("Click mouse to print coordinates\n");
	printf("'ESC key': Exit this program\n");
	printf("-------------------------------\n");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}