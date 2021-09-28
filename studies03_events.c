/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/09/28 15:33:13 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_RELEASE		3
#define X_EVENT_BUTTON_PRESS	4
#define X_EVENT_KEY_EXIT		17

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		x;
}	t_vars;

// Close windows and end program if button x is clicked
int	mlx_close(t_vars *vars)
{
	exit(0);
}

// Up key adds 1, Down key subs 1, esc key quit program
int key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
	{
		vars->x += 1;
		printf("x: %d\n", vars->x);
	}
	if (keycode == 125)
	{
		vars->x -= 1;
		printf("x: %d\n", vars->x);
	}
	return (0);
}

int key_release(int keycode, void *param)
{
	printf("Released!\n");
}

// Print button code and the coordinates where click was pressed
int mouse_hook(int button, int x, int y, t_vars *var)
{
	printf("Mouse pressed\nButton: %d \nCoordinates x: %d, y: %d\n", button, x, y);
}

int entered_in_window(int button, int x, int y, t_vars *vars)
{
    printf("Your mouse just entered to my WINDOW !!!!\n");
    return (0);
}
int out_from_window(int button, int x, int y, t_vars *vars)
{
    printf("Your mouse just gone (\n");
    return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.x = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	printf("-------------------------------------------\n");
	printf("x: %d", vars.x);
	printf("- Press up key to add 1\n");
	printf("- Press down key to substract 1\n");
	printf("- ESC key or x button exits this program\n");
	printf("-------------------------------------------\n");
	mlx_hook(vars.win, X_EVENT_KEY_PRESS, 1L<<0, key_press, &vars); 
	mlx_hook(vars.win, X_EVENT_KEY_RELEASE, 1L<<0, key_release, &vars);	
	mlx_hook(vars.win, X_EVENT_BUTTON_PRESS, 1L<<2, mouse_hook, &vars);	
	mlx_hook(vars.win, X_EVENT_KEY_EXIT, 1L<<0, mlx_close, &vars);
	mlx_hook(vars.win, 7, 1L<<4, entered_in_window,&vars); // NOT WORKING
    mlx_hook(vars.win, 8, 1L<<5, out_from_window, &vars); // NOT WORKING
	
	mlx_loop(vars.mlx);
}
