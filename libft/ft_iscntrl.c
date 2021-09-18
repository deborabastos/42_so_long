/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 22:40:17 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/28 15:31:07 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <ctype.h>
** DESCRIPTION:
**		The isnotprint() function tests if a character c is NOT printable 
**	according to ASCII table. Also called control character.
*/

int	ft_iscntrl(int c)
{
	if ((c >= 0 && c <= 31) || c == 127)
		return (1);
	return (0);
}
