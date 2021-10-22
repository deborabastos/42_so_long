/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/18 11:00:22 by dalves-p         ###   ########.fr       */
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

#define LEFT_KEY				123	
#define RIGHT_KEY				124	
#define UP_KEY					126
#define DOWN_KEY				125	
#define A_KEY					0
#define S_KEY					1	
#define D_KEY					2
#define W_KEY					13

#define ROWS					8
#define COLUMNS					10
#define SPRITE_H				64
#define SPRITE_W				64


typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_img
{
	void		*img_ptr;
	t_vector	size;
	t_vector	position;
	int			*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct	s_var {
	void		*mlx;
	void		*win;
	t_img		floor;
	t_img		tree;
}	t_var;

int	mlx_close(t_var vars)
{
	exit(0);
}

int key_press(int keycode, t_var *vars)
{
	if (keycode == 53)
		exit(0);
	return (0);
}


int	main(void)
{
	t_var	var;
	char	map[10] = {"1000110011"};
	int		i;
	int		j;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, COLUMNS * SPRITE_W, ROWS * SPRITE_H, "Sample");

	var.floor.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/floor.xpm", &var.floor.size.x, &var.floor.size.y);
	var.tree.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/tree.xpm", &var.tree.size.x, &var.tree.size.y);
	
	i = 0;
	j = 0;
	while (j < ROWS)
	{
		while (i < COLUMNS)
		{
			if(map[i] == '1')
				mlx_put_image_to_window(var.mlx, var.win, var.tree.img_ptr, SPRITE_W * i, SPRITE_H * j);
			else
				mlx_put_image_to_window(var.mlx, var.win, var.floor.img_ptr, SPRITE_W * i, SPRITE_H * j);	
			i++;
		}
		i = 0;
		j++;
	}
	


	mlx_hook(var.win, X_EVENT_KEY_PRESS, 1L<<0, key_press, &var); 
	mlx_hook(var.win, X_EVENT_KEY_EXIT, 1L<<0, mlx_close, &var);
	mlx_loop(var.mlx);
}
