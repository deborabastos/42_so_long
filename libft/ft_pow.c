/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:13:19 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/30 10:23:17 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <math.h>
** DESCRIPTION:
**		The ft_pow() function returns the value of a power applied to a number. 
**	An power lower than 0, returns 0.
*/

int	ft_pow(int nb, int power)
{
	int	result;

	result = nb;
	if (power < 0)
		return (0);
	else if (nb == 1 || power == 0)
		return (1);
	else
		result = result * ft_pow(nb, power - 1);
	return (result);
}
