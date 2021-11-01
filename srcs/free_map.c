/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:59:26 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/01 15:04:22 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int free_map(t_var *var)
{
	int 	row;

	row = 0;
	while (row < var->map.size.y)
	{
		free(var->map.mtx[row]);
		var->map.mtx[row]++;
	}
	return (0);
}
	