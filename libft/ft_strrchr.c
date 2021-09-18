/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:31:06 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/04 12:22:17 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = 0;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			ptr = (char *)s;
		s++;
	}
	if (*s == '\0' && (unsigned char)c == '\0')
		return ((char *)s);
	return (ptr);
}
