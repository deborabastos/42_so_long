/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/09/20 20:13:46 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "My Window");

	// Line 
	x = 150;
	y = 350;
	while (x < 350 && y > 150)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, 150, 111111);
		mlx_pixel_put(mlx_ptr, win_ptr, 150, x, 111111);
		mlx_pixel_put(mlx_ptr, win_ptr, 350, y, 111111);
		mlx_pixel_put(mlx_ptr, win_ptr, y, 350, 111111);
		x++;
		y--;
	}

	// Square
	x = 200;
	y = 200;	
	while (x < 300)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 2211);
		while (y < 300)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 2211);
			y++;			
		}
		y = 200;
		x++;
	}


	// Triangle
	x = 70;
	y = 40;
	while (x < 100 || y < 100)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 4915330);
		x++;
		y++;
	}

	x = 70;
	y = 40;
	while (x > 40 || y < 100)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 16716947);
		x--;
		y++;
	}
	
	x = 10;
	y = 100;
	while (x < 130)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 10494192);
		x++;
	}
	
	mlx_loop(mlx_ptr);
}
