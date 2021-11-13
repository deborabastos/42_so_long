/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:12:40 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/29 11:26:11 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <strings.h>
** DESCRIPTION:
**		The memmove() function copies len bytes from memory area src to memory area 
**	dst. The memory areas may overlap: copying takes place as though the bytes in 
**	src are first copied into a temporary array that does not overlap src or dst, 
**	and the bytes are then copied from the temporary array to dst.
**		It returns a pointer to dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (src < dst)
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	else if (src > dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
