/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:24:49 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/28 14:50:27 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
**		The ft_count_digit() counts how many digits has the integer.
*/

size_t	ft_count_digit(long long int n)
{
	size_t	c;

	if (n == 0)
		return (1);
	c = 0;
	if (n < -9223372036854775807)
	{
		c++;
		n = n / 10;
	}
	if (n < 0)
	{
		n = -n;
		c++;
	}
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}
