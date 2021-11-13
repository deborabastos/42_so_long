/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:02:03 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/29 18:47:52 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <math.h>
** DESCRIPTION:
**		The ft_sqrt() function compute the non-negative square root of nb.
*/

int	ft_sqrt(int nb)
{
	int	imp;
	int	c;

	imp = 1;
	c = 0;
	while (nb > 0)
	{
		nb = nb - imp;
		imp = imp + 2;
		c++;
	}
	if (nb == 0)
		return (c++);
	else
		return (0);
}
