/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:36 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/25 14:44:55 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>

# define PATH_MAP				"./maps/map.ber"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# define LEFT_KEY				123	
# define RIGHT_KEY				124	
# define UP_KEY					126
# define DOWN_KEY				125	
# define A_KEY					0
# define S_KEY					1	
# define D_KEY					2
# define W_KEY					13
# define ESC 					53

# define ROWS					8
# define SPRITE_H				64
# define SPRITE_W				64

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

typedef struct s_var {
	void		*mlx;
	void		*win;
	t_map		map;
	t_img		sprite;
	t_img		floor;
	t_img		tree;
	t_img		exit;
	t_img		collectible;
}	t_var;

int	load_map(t_var var);
int	key_press(int key);
int	mlx_close(void);
int	get_map_x(t_var var);
int	get_map_y(t_var var);
int	check_map(t_var var);
int	error(char *msg);

#endif
