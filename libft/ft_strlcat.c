/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:15:33 by dalves-p          #+#    #+#             */
/*   Updated: 2021/05/31 10:36:32 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
