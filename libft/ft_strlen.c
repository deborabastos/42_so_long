/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:15:43 by dalves-p          #+#    #+#             */
/*   Updated: 2021/07/12 17:08:54 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <strings.h>
** DESCRIPTION:
**		The strlen() function calculates the length of the string pointed to by 
**	s, excluding the terminating null byte ('\0').
**		It returns the number of bytes in the string pointed to by s.
*/

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c] != '\0')
		c++;
	return (c);
}
