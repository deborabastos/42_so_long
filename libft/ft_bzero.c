/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:15:11 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/26 16:57:24 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <strings.h>
** DESCRIPTION:
** 		The bzero() function writes n zeroed bytes to the string s. If n is
**	zero, bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
