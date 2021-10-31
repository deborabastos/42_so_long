/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   studies07_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/31 15:40:58 by dalves-p         ###   ########.fr       */
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

#define SPRITE_SIZE				64

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
	t_img		sprite;
}	t_var;

int	mlx_close(t_var vars)
{
	exit(0);
}

int key_press(int keycode, t_var *vars)
{
	printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	if ((keycode == LEFT_KEY || keycode == A_KEY) && (vars->sprite.position.x > 0))
	{
		vars->sprite.position.x -= vars->sprite.size.x;
	}
	if ((keycode == RIGHT_KEY || keycode == D_KEY) && (vars->sprite.position.x < SPRITE_SIZE * 7))
	{
		vars->sprite.position.x += vars->sprite.size.x;
	}
	if ((keycode == DOWN_KEY || keycode == S_KEY) && (vars->sprite.position.y < SPRITE_SIZE * 7))
	{
		vars->sprite.position.y += vars->sprite.size.y;
	}
	if ((keycode == UP_KEY || keycode == W_KEY) && (vars->sprite.position.y > 0))
	{
		vars->sprite.position.y -= vars->sprite.size.y;
	}

	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.img_ptr, vars->sprite.position.x, vars->sprite.position.y);

	return (0);
}

int	main(void)
{
	t_var	var;

	var.sprite.position.x = 0;
	var.sprite.position.y = 0;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 8*SPRITE_SIZE, 8*SPRITE_SIZE, "Sample");

	var.sprite.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/block.xpm", &var.sprite.size.x, &var.sprite.size.y);
	mlx_put_image_to_window(var.mlx, var.win, var.sprite.img_ptr, var.sprite.position.x, var.sprite.position.y);

	mlx_hook(var.win, X_EVENT_KEY_PRESS, 1L<<0, key_press, &var); 
	mlx_hook(var.win, X_EVENT_KEY_EXIT, 1L<<0, mlx_close, &var);
	mlx_loop(var.mlx);
}
