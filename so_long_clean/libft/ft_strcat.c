/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:01:03 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/29 18:10:58 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <strings.h>
** DESCRIPTION:
**		The strcat() function appends the src string to the dest string, 
**	overwriting the terminating null byte ('\0') at the end of dest, and then 
**	adds a terminating null byte.  The strings may not overlap, and the dest 
**	string must have enough space for the result.
**		It returns a pointer to the resulting string dest.
*/

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	size_dest;

	i = 0;
	size_dest = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[size_dest] = src[i];
		i++;
		size_dest++;
	}
	dest[size_dest] = '\0';
	return (dest);
}
