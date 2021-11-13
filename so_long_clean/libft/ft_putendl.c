/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:41:16 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/29 16:19:53 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
**		The ft_putendl() function outputs the string ’s’ to the standard output, 
**	followed by a newline.
*/

void	ft_putendl(char *s)
{
	if (s != NULL)
	{
		while (*s != '\0')
		{
			write(1, s, 1);
			s++;
		}
		write(1, "\n", 1);
	}
}
