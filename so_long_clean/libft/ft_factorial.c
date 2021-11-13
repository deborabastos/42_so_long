/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:51:52 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/29 18:42:21 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
**		The ft_factorial() function returns the result of a factorial operation 
**	based on the number given as a parameter. If the argument is not valid, it 
**	returns 0.
*/

int	ft_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (1);
	else
		result = nb * ft_factorial(nb - 1);
	return (result);
}
