/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:16:00 by dalves-p          #+#    #+#             */
/*   Updated: 2021/07/07 15:30:09 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
**		The ft_utoa_base() function 
*/

char	*ft_strrev(char *str)
{
	size_t	size;
	size_t	i;
	char	aux;

	size = ft_strlen(str);
	str[size + 1] = '\0';
	size--;
	i = 0;
	while (i < size)
	{
		aux = str[i];
		str[i] = str[size];
		str[size] = aux;
		i++;
		size--;
	}
	return (str);
}
