/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   studies06_image_rainbow.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/09/30 15:34:12 by dalves-p         ###   ########.fr       */
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

#define KEY_ESC			53

# define TILE_SIZE 64
# define ROWS 5
# define COLS 7
# define WIDTH COLS * TILE_SIZE // 448
# define HEIGHT ROWS * TILE_SIZE // 320


typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_mlx;


int	rainbow(t_mlx *mlx)
{
	int		count_w;
	int		count_h;
	
	count_h = -1;
	while (++count_h < HEIGHT)
	{
		count_w = -1;
		while (++count_w < TILE_SIZE)
			mlx->img.data[count_h * WIDTH + count_w] = 0xFF00FF;			
		while (++count_w < TILE_SIZE * 2)
			mlx->img.data[count_h * WIDTH + count_w] = 0x4B0082;
		while (++count_w < TILE_SIZE * 3)
			mlx->img.data[count_h * WIDTH + count_w] = 0x0000FF;
		while (++count_w < TILE_SIZE * 4)
			mlx->img.data[count_h * WIDTH + count_w] = 0x00FF00;
		while (++count_w < TILE_SIZE * 5)			
			mlx->img.data[count_h * WIDTH + count_w] = 0xFFFF00;
		while (++count_w < TILE_SIZE * 6)
			mlx->img.data[count_h * WIDTH + count_w] = 0xFF7F00;
		while (++count_w < TILE_SIZE * 7)			
			mlx->img.data[count_h * WIDTH + count_w] = 0xFF0000;
	}
}


int		deal_key(int key_code, t_mlx *mlx)
{
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int 	close_win(t_mlx *mlx)
{
		exit(0);
}

void	window_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Rainbow");
}

void	img_init(t_mlx *mlx)
{
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
}

int		main_loop(t_mlx *mlx)
{
	rainbow(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}

int		main(void)
{
	t_mlx mlx;

	window_init(&mlx);
	img_init(&mlx);
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, &deal_key, &mlx);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, &close_win, &mlx);
	mlx_loop_hook(mlx.mlx, &main_loop, &mlx);
	mlx_loop(mlx.mlx);
}