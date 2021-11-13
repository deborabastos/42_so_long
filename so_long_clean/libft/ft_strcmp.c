/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:35:48 by dalves-p          #+#    #+#             */
/*   Updated: 2021/07/01 22:13:03 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: <strings.h>
** DESCRIPTION:
**		The strncmp() compares bytes of s1 and s2.
**		It returns an integer less than, equal to, or greater than zero if s1 
**	(or the first n bytes thereof) is found, respectively, to be less than, to 
**	match, or be greater than s2.
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	c;

	c = 0;
	while ((unsigned char)s1[c] == (unsigned char)s2[c]
		&& (unsigned char)s1[c] != '\0' && (unsigned char)s2[c] != '\0')
	{
		c++;
	}
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
