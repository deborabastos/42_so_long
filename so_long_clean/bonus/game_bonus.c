/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:24:18 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/12 17:46:37 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	get_init_position(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var->map.size.y)
	{
		col = 0;
		while (col <= var->map.size.x)
		{
			if (var->map.mtx[row][col] == 'P')
			{
				var->img.pos.x = col;
				var->img.pos.y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	count_collec(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	var->game.count_collec = 0;
	while (row < var->map.size.y)
	{
		col = 0;
		while (col <= var->map.size.x)
		{
			if (var->map.mtx[row][col] == 'C')
				var->game.count_collec++;
			col++;
		}
		row++;
	}
	return (var->game.count_collec);
}

int	check_collect(t_var *var)
{
	if (count_collec(var) == 0)
	{
		free_exit(var, "\e[34m\e[1mCONGRATS\n!!!! You WON !!!!\e[0m\n");
	}
	else
		printf("\e[35m\e[1mPlease, collect all diamonds!!!\e[0m\n");
	return (0);
}

int	print_steps(t_var *var)
{
	char	*str;

	str = ft_itoa(var->game.count_steps);
	mlx_string_put(var->mlx, var->win, (var->img.pos.x * SPRITE_W) + 5,
		(var->img.pos.y * SPRITE_H) + 10, 0x833000, str);
	free(str);
	return (0);
}
