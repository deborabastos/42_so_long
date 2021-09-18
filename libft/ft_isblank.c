/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 22:30:32 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/28 10:53:11 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <ctype.h>
** DESCRIPTION:
** 		The isblank() function checks for a blank character; that is, a space
**	or a tab.
*/

int	ft_isblank(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
