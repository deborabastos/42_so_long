/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:08:17 by dalves-p          #+#    #+#             */
/*   Updated: 2021/07/06 18:22:32 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
**		The ft_itoa() function allocates (with malloc)) and returns a string 
**	representing the integer received as an argument. Negative numbers must be 
**	handled.
**		It returns the string representing the integer or NULL if the allocation 
**	fails.
*/

char	*ft_itoa(int n)
{
	int				size;
	unsigned int	unbr;
	char			*str;

	size = ft_count_digit(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	unbr = n;
	if (n < 0)
	{
		str[0] = '-';
		unbr = -unbr;
	}
	str[size] = '\0';
	size--;
	while ((n < 0 && size >= 1) || (n >= 0 && size >= 0))
	{
		str[size] = (unbr % 10 + '0');
		unbr = unbr / 10;
		size--;
	}
	return (str);
}
