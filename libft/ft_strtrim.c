/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:59:37 by dalves-p          #+#    #+#             */
/*   Updated: 2021/06/08 14:25:27 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	int		i;
	char	*str;

	if (!s1 || !set)
		return (0);
	beg = 0;
	while (s1[beg] != '\0' && (ft_strchr(set, s1[beg]) != 0))
		beg++;
	end = ft_strlen(s1);
	while (end > beg && (ft_strchr(set, s1[end]) != 0))
		end--;
	str = malloc((end - beg + 2) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s1[i] && beg + i <= end)
	{
		str[i] = s1[beg + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
