/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:45:38 by dalves-p          #+#    #+#             */
/*   Updated: 2021/10/20 20:00:30 by dalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_row(char *line)
{
	int		col;	

	col = 0;
	while (line[col])
	{
		if (line[col] != '1')
		{
			perror("Top or Down wall not configured");
			exit (EXIT_FAILURE);
		}
		col++;
	}
	return (0);
}

int	check_walls(t_var var)
{
	int		fd;
	int		row;
	char	*line;

	row = 0;
	fd = open(PATH_MAP, O_RDONLY);
	while (ft_gnl(fd, &line))
	{
		if (row == 0)
			check_row(line);
		if (line[0] != '1' || line[var.map.size.x - 1] != '1')
		{
			perror("Lateral wall not configured");
			exit (EXIT_FAILURE);
		}
		row++;
	}
	if (row == var.map.size.y - 1)
		check_row(line);
	close(fd);
	return (0);
}

char	*check_pec(t_var var, char *line, char	*has)
{
	int		col;

	col = 0;
	while (col <= var.map.size.x)
	{
		if (line[col] == 'P')
			has[0] = 'P';
		if (line[col] == 'E')
			has[1] = 'E';
		if (line[col] == 'C')
			has[2] = 'C';
		col++;
	}
	return (has);
}

int	check_sprites(t_var var)
{
	int		fd;
	char	*has;
	char	*line;

	has = malloc(3 * sizeof(char));
	fd = open(PATH_MAP, O_RDONLY);
	while (ft_gnl(fd, &line) > 0)
		check_pec(var, line, has);
	printf("%c%c%c\n", has[0], has[1], has[2]);
	if (has[0] != 'P' || has[1] != 'E' || has[2] != 'C')
		printf("missing\n");
	free(has);
	close(fd);
	return (0);
}

int	check_map(t_var var)
{
	check_walls(var);
	check_sprites(var);
	return (0);
}
