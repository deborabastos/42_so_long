/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:22:49 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/29 16:20:55 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
**		The ft_putstr() function outputs the string ’s’ to the standard output.
*/

void	ft_putstr(char *s)
{
	if (s != NULL)
	{
		while (*s != '\0')
		{
			write(1, s, 1);
			s++;
		}		
	}
}
