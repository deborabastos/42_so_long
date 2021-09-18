/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:35:18 by dalves-p          #+#    #+#             */
/*   Updated: 2021/09/17 16:36:10 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(char *dst, char *src, size_t n);
int		get_next_line(int fd, char **line);

#endif