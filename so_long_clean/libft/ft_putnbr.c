/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:49:14 by dalves-p          #+#    #+#             */
/*   Updated: 2021/08/12 20:53:46 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
**		The ft_putnbr() function outputs the integer ’n’ to the standard output.
*/

void	ft_putnbr(int n)
{
	if (n >= 0 && n < 10)
	{
		ft_putchar((n + '0'));
	}
	else if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
}
