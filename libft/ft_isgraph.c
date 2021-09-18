/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:54:19 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/28 10:57:07 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <ctype.h>
** DESCRIPTION:
** 		 The isgraph() function checks for any printable character except space.
*/

int	ft_isgraph(int c)
{
	if (c > 32 && c <= 126)
		return (1);
	return (0);
}
