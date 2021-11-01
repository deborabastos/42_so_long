/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:06:36 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/01 15:01:28 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h> // write, read
# include <stdlib.h> // malloc, free, exit
# include <stdio.h> //printf, perror
# include <string.h> // strerror
# include <fcntl.h> // open, close, read

# include "mlx/mlx.h"
# include "libft/libft.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# if defined(__APPLE__) && defined(__MACH__)
#  define LEFT_KEY				123	
#  define RIGHT_KEY				124	
#  define UP_KEY				126
#  define DOWN_KEY				125	
#  define A_KEY					0
#  define S_KEY					1
#  define D_KEY					2
#  define W_KEY					13
#  define ESC 					53

# else
#  define W_KEY					119
#  define S_KEY					115
#  define D_KEY					100
#  define A_KEY					97
#  define ESC					65307
# endif

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
	t_vector	pos;
	int			*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_map
{
	char		**mtx;
	t_vector	size;
}	t_map;

typedef struct s_game
{
	int			count_collec;
	int			count_steps;

}	t_game;

typedef struct s_var
{
	void		*mlx;
	void		*win;
	t_game		game;
	t_map		map;
	t_img		img;
	// t_img		spt;
	// t_img		floor;
	// t_img		tree;
	// t_img		exit;
	// t_img		collectible;
}	t_var;

int	get_x_y(t_var *var, char **argv);
int	init(t_var *var);
int	get_map(t_var *var, char **argv);
int	check_args(int argc, char **argv);
int	print_map(t_var var);
int	key_press(int key, t_var *vars);
int	mlx_close(void);
int	get_map_x(t_var var);
int	get_map_y(t_var var);
int	check_map(t_var var);
int	error(char *msg);
int	get_init_position(t_var *var);
int	count_collec(t_var *var);
int	check_collect(t_var *var);
int	movements(int key, t_var *var);
int	free_map(t_var *var);
int print_steps(t_var *var);

#endif
