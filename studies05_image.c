/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/09/28 22:47:38 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

#define WIN_WIDTH				800
#define WIN_HEIGHT				600
#define IMG_WIDTH				400
#define IMG_HEIGHT				300

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_EXIT		17

typedef struct s_img
{
	void	*img_ptr;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_mlx {
	void	*mlx_ptr;
	void	*win;
}	t_mlx;




// Close windows and end program if button x is clicked
int	mlx_close(t_mlx *vars)
{
	exit(0);
}

// esc key quit program
int key_exit(int keycode, t_mlx *vars)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	main(void)
{
	t_mlx	mlx;
	t_img	img;
	int		count_w;
	int		count_h;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Image exemple");
	img.img_ptr= mlx_new_image(mlx.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = (int *)mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	//The reason why I cast to (int *): If I let this as void * type, whenever I refer to the array values, I need to multiply them by 4.
	//Check out keuhdall's github linked in my README for more information.

	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			if (count_w % 2)
				img.addr[count_h * IMG_WIDTH + count_w] = 0xFFFFFF;
			else
				img.addr[count_h * IMG_WIDTH + count_w] = 0xFF00FF;
		}
	}

	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr, 200, 150);


	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 1L<<0, key_exit, &mlx); 
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 1L<<0, mlx_close, &mlx);

	
	mlx_loop(mlx.mlx_ptr);
}
