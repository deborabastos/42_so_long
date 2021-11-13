/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:53:06 by dalves-p          #+#    #+#             */
/*   Updated: 2021/08/20 22:19:13 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LIBRARY: N/A
** DESCRIPTION:
**		The ft_split() allocates (with malloc) and returns an array of strings 
**	obtained by splitting ’s’ using the character ’c’ as a delimiter. The array 
**	must be ended by a NULL pointer.
**		It returns the array of new strings resulting from the split or NULL if 
**	the allocation fails.
*/

static char	**get_strs(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	i = 0;
	j = 0;
	index = -1;
	split = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	while (s[i] != '\0')
	{
		if (s[i] != c && index < 0)
			index = i;
		else if (s[i] == c && index >= 0)
		{
			split[j] = ft_substr(s, index, (i - index));
			index = -1;
			j++;
		}
		i++;
	}
	split[j] = ft_substr(s, index, (i - index));
	j++;
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*scpy;

	if (!s)
		return (0);
	scpy = ft_strtrim(s, &c);
	if (!scpy)
		return (0);
	if (ft_count_words(scpy, c) == 0)
	{
		split = malloc(1 * sizeof(char *));
		split[0] = NULL;
		free(scpy);
		return (split);
	}
	split = get_strs(scpy, c);
	free(scpy);
	return (split);
}
