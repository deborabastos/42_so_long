/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   studies04_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/09/30 15:34:26 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include "../mlx/mlx.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_EXIT		17

// Close windows and end program if button x is clicked
int	mlx_close(void *win)
{
	exit(0);
}

// Up key adds 1, Down key subs 1, esc key quit program
int key_press(int keycode, 	void *win)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int main(void)
{
	void *mlx;
	void *win;
	void *img;

	int		img_width;
	int 	img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");

	img = mlx_xpm_file_to_image(mlx, "./img/wall_n.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	img = mlx_xpm_file_to_image(mlx, "./img/wall_s.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 64, 0);
	img = mlx_xpm_file_to_image(mlx, "./img/wall_e.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 128, 0);
	img = mlx_xpm_file_to_image(mlx, "./img/wall_w.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 192, 0);

	mlx_hook(win, X_EVENT_KEY_PRESS, 1L<<0, key_press, win); 
	mlx_hook(win, X_EVENT_KEY_EXIT, 1L<<0, mlx_close, win);

	mlx_loop(mlx);
	return (0);
}
