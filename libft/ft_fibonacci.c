/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:27:24 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/29 18:37:22 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
** 		The ft_fibonacci() function returns the n-th element of the Fibonacci
**	sequence, the first element being at the 0 index. It considers that Fibonacci
**	sequence starts like 0,1,1,2. If the index is less than 0, the function should
**	return -1.
*/

int	ft_fibonacci(int index)
{
	int	result;

	result = 0;
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index > 1)
	{
		result = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	}
	return (result);
}
