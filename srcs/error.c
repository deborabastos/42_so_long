/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:58:18 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/20 21:00:54 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error(char *msg)
{
	perror(msg);
	exit (EXIT_FAILURE);
	return (0);
}
