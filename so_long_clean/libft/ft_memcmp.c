/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:15:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/29 11:18:53 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <strings.h>
** DESCRIPTION:
**		The memcmp() function compares the first n bytes (each interpreted as 
**	unsigned char) of the memory areas s1 and s2.
**		It returns an integer less than, equal to, or greater than zero if the 
**	first n bytes of s1 is found, respectively, to be less than, to match, or be 
**	greater than the first n bytes of s2.
**		For a nonzero return value, the sign is determined by the sign of the 
**	difference between the first pair of bytes (interpreted as unsigned char) 
**	that differ in s1 and s2.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
