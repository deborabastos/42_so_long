/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:45:38 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/20 11:00:30 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls(t_var var)
{
	int		fd;
	int		row;
	int		col;	
	char	*line;

	row = 0;
	col = 0;
	fd = open(PATH_MAP, O_RDONLY);
	if (fd == -1)
		return (1);
	// printf("%d\n", var.map.size.y);
	// printf("%d\n", var.map.size.x);
	while (ft_gnl(fd, &line))
	{
		if (row == 0)
		{
			// printf("Up %s\n", line);
			while (line[col])
			{
				if (line[col] != '1')
				{
					perror("Top wall not configured");
					exit (EXIT_FAILURE);
				}
				col++;
			}
		}
		// printf("linha = %d - primeiro %c - último %c\n", row + 1, line[0], line[var.map.size.x - 1]);
		if (line[0] != '1' || line[var.map.size.x - 1] != '1')
		{
			perror("Lateral wall not configured");
			exit (EXIT_FAILURE);
		}


		row++;
	}
	col = 0;
	if (row == var.map.size.y - 1)
	{
		while (line[col])
		{
			if (line[col] != '1')
			{
				perror("Down wall not configured");
				exit (EXIT_FAILURE);
			}
			col++;
		}		
	}
	return (0);
}

// int	check_walls(t_var var)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("./maps/map.ber", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	while (ft_gnl(fd, &line) >= 0)
// 	{
		
// 	}
// 	close(fd);	
// 	return (0);
// }
