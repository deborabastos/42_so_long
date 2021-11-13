/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:49:14 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/28 14:48:26 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
**		The ft_putlnbr() function outputs the unsigned integer ’n’ to the 
**	standard output.
*/

void	ft_putlnbr(long long int n)
{		
	if (n >= 0 && n < 10)
		ft_putchar((n + '0'));
	else if (n < -9223372036854775807)
		ft_putstr("-9223372036854775808");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putlnbr(-n);
	}
	else
	{
		ft_putlnbr((n / 10));
		ft_putlnbr((n % 10));
	}
}
