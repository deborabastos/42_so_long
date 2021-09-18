/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uinttoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:08:17 by dalves-p          #+#    #+#             */
/*   Updated: 2021/08/19 11:02:02 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
**		The ft_uinttoa_base() function 
*/

static unsigned int	ft_is_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) == 0 || ft_strlen(str) == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_uinttoa_base(uintptr_t n, char *base)
{
	uintptr_t	base_size;
	int			mod;
	char		*str;
	char		*str_aux;	
	char		dig[2];

	base_size = ft_strlen(base);
	if (ft_is_base(base) == 0)
		return (NULL);
	str = NULL;
	if (n == 0)
		str = ft_strdup("0");
	dig[1] = '\0';
	while (n > 0)
	{
		str_aux = str;
		mod = n % base_size;
		dig[0] = base[mod];
		str = ft_strjoin(str, dig);
		free(str_aux);
		n = n / base_size;
	}
	ft_strrev(str);
	return (str);
}
