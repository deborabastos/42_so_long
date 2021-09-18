/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:15:33 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/29 12:27:04 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <strings.h>
** DESCRIPTION:
**		The strlcat() function appends string src to the end of dst. It will 
**	append at most dstsize – strlen(dst) – 1 characters. It will then NUL-
**	terminate, unless dstsize is 0 or the original dst string was longer than 
**	dstsize (in practice this should not happen as it means that either dstsize 
**	is incorrect or that dst is not a proper string).
**		It returns the combined length of both src and dst strings (not counting 
**	their terminating null characters). This result is used to determine whether 
**	the final string was truncated.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	sz_dst;
	size_t	sz_src;

	i = 0;
	sz_dst = ft_strlen(dst);
	sz_src = ft_strlen(src);
	if (dstsize == 0 || sz_dst > dstsize)
		return (sz_src + dstsize);
	else if (dstsize > sz_dst)
	{
		while (src[i] != '\0' && i < (dstsize - sz_dst - 1))
		{
			dst[sz_dst + i] = src[i];
			i++;
		}
		dst[sz_dst + i] = '\0';
	}
	return (sz_src + sz_dst);
}
