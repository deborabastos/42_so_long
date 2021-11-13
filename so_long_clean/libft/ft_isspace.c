/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 22:36:43 by dalves-p          #+#    #+#             */
/*   Updated: 2021/08/19 11:03:24 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <ctype.h>
** DESCRIPTION:
** 		The isspace() function tests for white-space characters. That is:
**	form-feed ('\f'), newline ('\n'), carriage return ('\r'), horizontal tab 
**	('\t'), and vertical tab ('\v').
*/

int	ft_isspace(int c)
{
	if ((c == ' ' || c == '\r' || c == '\n' || c == '\f' || c == '\v'
			|| c == '\t'))
		return (1);
	return (0);
}
