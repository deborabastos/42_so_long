/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/07 12:37:30 by dalves-p         ###   ########.fr       */
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

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_img
{
	void		*img_ptr;
	t_vector	size;
	int			*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct	s_var {
	void		*mlx;
	void		*win;
	t_img		sprite;
	t_vector	sprite_pos;
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
	if (keycode == 124)
	{
		vars->sprite_pos.x += vars->sprite.size.x;
	}

	return (0);
}



int	main(void)
{
	t_var	var;
	t_img	sprite;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 500, 500, "Sample");

	sprite.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/block.xpm", &sprite.size.x, &sprite.size.y);
	var.sprite_pos.x = 0;
	var.sprite_pos.y = 0;	
	mlx_put_image_to_window(var.mlx, var.win, sprite.img_ptr, var.sprite_pos.x, var.sprite_pos.y);

	mlx_hook(var.win, X_EVENT_KEY_PRESS, 1L<<0, key_press, &var); 
	mlx_hook(var.win, X_EVENT_KEY_EXIT, 1L<<0, mlx_close, &var);
	
	mlx_loop(var.mlx);
}
