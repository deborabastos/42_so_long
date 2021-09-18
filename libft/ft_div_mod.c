/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:28:46 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/29 16:56:46 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
** 		The ft_div_mod() function divides parameters a by b and stores the result
**	in the int pointed by div. It also stores the remainder of the division of 
**	a by b in the int pointed by mod.
*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = (a / b);
		*mod = (a % b);
	}
}
