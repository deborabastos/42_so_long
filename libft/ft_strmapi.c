/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:03:52 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/10 13:49:00 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	size_t			size_str;

	if (!s || !f)
		return (0);
	size_str = ft_strlen(s);
	str = (char *)malloc((size_str + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s, (size_str + 1));
	i = 0;
	while (str[i] != '\0')
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
