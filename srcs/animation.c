/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:42:35 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/09 14:54:45 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	enemy_animation(t_var *var)
{
	if (var->enemy.pos.x % 2 == 0)
		var->img.img_ptr = mlx_xpm_file_to_image(var->mlx, "./img/enemy1.xpm",
				&var->enemy.size.x, &var->enemy.size.y);
	else
		var->img.img_ptr = mlx_xpm_file_to_image(var->mlx, "./img/enemy2.xpm",
				&var->enemy.size.x, &var->enemy.size.y);
	return (0);
}
