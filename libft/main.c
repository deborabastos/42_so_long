/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 20:54:29 by dalves-p          #+#    #+#             */
/*   Updated: 2021/11/01 19:07:01 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Para compilar:
// clang get_next_line_utils.c get_next_line.c main.c -D BUFFER_SIZE=50 && ./a.out

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"


int	main(void)
{
	int		fd;
	char	*line;

	// fd = open("song.txt", O_RDONLY);
	// get_next_line(fd, &line);
	// printf("%s\n", line);
	

	// get_next_line(fd, &line);
	// printf("%s\n", line);

	fd = open("song.txt", O_RDONLY);
	while (ft_gnl(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
