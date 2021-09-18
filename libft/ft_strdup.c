/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 21:40:02 by dalves-p          #+#    #+#             */
/*   Updated: 2021/05/31 15:10:34 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str_dup;
	int		s_len;

	s_len = ft_strlen(s1);
	str_dup = (char *)malloc((s_len + 1) * sizeof(char));
	if (!s1 || !str_dup)
		return (0);
	ft_strlcpy(str_dup, s1, (s_len + 1));
	return (str_dup);
}
