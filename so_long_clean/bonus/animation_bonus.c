/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:42:35 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/12 17:46:18 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	enemy_animation(t_var *var)
{
	if (var->enemy.pos.x % 2 == 0)
		var->img.img_ptr = mlx_xpm_file_to_image(var->mlx, "./img/enemy1.xpm",
				&var->img.size.x, &var->img.size.y);
	else
		var->img.img_ptr = mlx_xpm_file_to_image(var->mlx, "./img/enemy2.xpm",
				&var->img.size.x, &var->img.size.y);
	return (0);
}
