/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:08:17 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/02 16:51:38 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	ft_count_len(int n)
{
	int				size;
	unsigned int	unbr;

	unbr = n;
	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		unbr = -unbr;
	}
	while (unbr > 0)
	{
		size++;
		unbr = unbr / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int				size;
	unsigned int	unbr;
	char			*str;

	size = ft_count_len(n);
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
