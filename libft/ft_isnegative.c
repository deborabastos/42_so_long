/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnegative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:24:17 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/29 16:26:04 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
**		The ft_isnegative() function checks if a number is negative.
*/

int	ft_isnegative(int n)
{
	if (n < 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
