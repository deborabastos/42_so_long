/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 21:04:23 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/26 17:03:41 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	LIBRARY: <stdlib.h>
**	DESCRIPTION:
** 		The calloc() function allocates the requested memory and returns a pointer 
**	to it. The difference in malloc and calloc is that malloc does not set the 
**	memory to zero where as calloc sets allocated memory to zero.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (0);
	ft_memset(p, 0, (count * size));
	return (p);
}
