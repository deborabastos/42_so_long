/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:35:15 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/04 00:34:45 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ptr;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (0);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	ptr = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!ptr)
		return (0);
	if (s1)
		ft_strcpy_gnl(ptr, s1, len_s1);
	ft_strcpy_gnl(ptr + (len_s1), s2, len_s2);
	free(s1);
	return (ptr);
}

static int	is_line(char *backup)
{
	int	i;

	i = 0;
	if (!backup)
		return (0);
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*get_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	if (!backup)
		return (0);
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_backup(char *backup)
{
	int		i;
	int		j;
	char	*newbackup;

	i = 0;
	j = 0;
	if (!backup)
		return (0);
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == 0)
	{
		free(backup);
		return (0);
	}
	newbackup = malloc((ft_strlen(backup) - i + 1) * sizeof(char));
	if (!newbackup)
		return (0);
	i++;
	while (backup[i] != '\0')
		newbackup[j++] = backup[i++];
	newbackup[j] = '\0';
	free(backup);
	return (newbackup);
}

int	ft_gnl(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		*buffer;
	int			buffsize;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0 || fd > OPEN_MAX)
		return (-1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffsize = 1;
	while (((is_line(backup[fd])) == 0) && (buffsize != 0))
	{
		buffsize = read(fd, buffer, BUFFER_SIZE);
		if (buffsize == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[buffsize] = '\0';
		backup[fd] = ft_strjoin_gnl(backup[fd], buffer);
	}
	free(buffer);
	*line = get_line(backup[fd]);
	backup[fd] = get_backup(backup[fd]);
	if (buffsize == 0)
		return (0);
	return (1);
}
