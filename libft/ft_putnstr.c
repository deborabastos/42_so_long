/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:22:49 by dalves-p          #+#    #+#             */
/*   Updated: 2021/08/19 10:59:02 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
**		The ft_putstr() function outputs the string ’s’ to the standard output 
**	limited to n chars.
*/

void	ft_putnstr(char *s, int n)
{
	if (!s)
		ft_putnstr("(null)", n);
	else
	{
		while (*s && n > 0)
		{
			write(1, s, 1);
			s++;
			n--;
		}		
	}
}
