/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:58:19 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/16 23:12:47 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count(char **map)
{
	int	count;

	count = 0;
	while (map[count])
	count++;
	return (count);
}

int	count_map(int fd, char *line)
{
	int	count;

	count = 0;
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

void	fill_by_line(char **map, char *line, int fd)
{
	int	i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
}

char	**fill_map(char **av)
{
	char	*line;
	char	**map;
	int		count;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	line = get_next_line(fd);
	if (line == NULL)
		ft_error();
	count = count_map(fd, line);
	close(fd);
	fd = open(av[1], O_RDONLY);
	map = malloc(sizeof(char *) * (count + 1));
	if (!map)
		exit(1);
	fill_by_line(map, line, fd);
	close(fd);
	return (map);
}

void	check_arg(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".ber") != 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	else
		ft_error();
}
