/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/18 15:12:50 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

typedef struct s_map
{
	void		*map_ptr;
	t_vector	size;
}	t_map;

typedef struct	s_var {
	void		*mlx;
	void		*win;
	t_map		map;
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


int get_map(t_var var)
{
	int		fd;
	char	*line;
	int		i;

	var.floor.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/floor.xpm", &var.floor.size.x, &var.floor.size.y);
	var.tree.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/tree.xpm", &var.tree.size.x, &var.tree.size.y);
	

	fd = open("./maps/map.ber", O_RDONLY);
	if (fd == -1)
		return (1);
	ft_gnl(fd, &line);
	while (line[i])
	{
		printf("%c", line[i]);
		if(line[i] == '1')
			mlx_put_image_to_window(var.mlx, var.win, var.tree.img_ptr, SPRITE_W * i, 0);
		else
			mlx_put_image_to_window(var.mlx, var.win, var.floor.img_ptr, SPRITE_W * i, 0);	
		i++;
	}

	// while (ft_gnl(fd, &line) > 0)
	// {
		// printf("%s\n", line);

		// if(map[i] == '1')
			// mlx_put_image_to_window(var.mlx, var.win, var.tree.img_ptr, SPRITE_W * i, SPRITE_H * j);
		// else
			// mlx_put_image_to_window(var.mlx, var.win, var.floor.img_ptr, SPRITE_W * i, SPRITE_H * j);	
	
		// free(line);		
	// }
	// free(line);
	// close(fd);
	
	// i = 0;
	// j = 0;
	// while (j < ROWS)
	// {
	// 	while (i < COLUMNS)
	// 	{
	// 		if(map[i] == '1')
	// 			mlx_put_image_to_window(var.mlx, var.win, var.tree.img_ptr, SPRITE_W * i, SPRITE_H * j);
	// 		else
	// 			mlx_put_image_to_window(var.mlx, var.win, var.floor.img_ptr, SPRITE_W * i, SPRITE_H * j);	
	// 		i++;
	// 	}
	// 	i = 0;
	// 	j++;
	// }
	return (0);
}


int	main(void)
{
	t_var	var;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, COLUMNS * SPRITE_W, ROWS * SPRITE_H, "Sample");
	get_map(var);

	mlx_hook(var.win, X_EVENT_KEY_PRESS, 1L<<0, key_press, &var); 
	mlx_hook(var.win, X_EVENT_KEY_EXIT, 1L<<0, mlx_close, &var);
	mlx_loop(var.mlx);
}
