/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:15:16 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/17 00:04:51 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_path(char **map)
{
	write(2, "Error is not valid path\n", 25);
	ft_free(map);
	exit(1);
}

int	check_valid_pos(char **map, int j, int i)
{
	int	valid;

	valid = 0;
	if (map[j][i + 1] == '0' || map[j][i + 1] == 'C')
	{
		map[j][i + 1] = 'P';
		valid = 1;
	}
	if (map[j][i - 1] == '0' || map[j][i - 1] == 'C')
	{
		map[j][i - 1] = 'P';
		valid = 1;
	}
	if (map[j + 1][i] == '0' || map[j + 1][i] == 'C')
	{
		map[j + 1][i] = 'P';
		valid = 1;
	}
	if (map[j - 1][i] == '0' || map[j - 1][i] == 'C')
	{
		map[j - 1][i] = 'P';
		valid = 1;
	}
	return (valid);
}

void	valid_or_no(char **map, int row, int col)
{
	int	i;
	int	j;

	j = 0;
	while (j < row)
	{
		i = 0;
		while (i < col)
		{
			if (map[j][i] == 'E')
			{
				if (map[j][i + 1] == 'P' || map[j][i - 1] == 'P')
				i++;
				else if (map[j - 1][i] == 'P' || map[j + 1][i] == 'P')
				i++;
				else
					error_path(map);
			}
			if (map[j][i] == 'C')
				error_path(map);
			i++;
		}
		j++;
	}
}

void	if_valid_path(char **map, int row, int col)
{
	int	i;
	int	j;

	j = 0;
	while (j < row)
	{
		i = 0;
		while (i < col)
		{
			if (map[j][i] == 'P')
			{
				if (check_valid_pos(map, j, i))
				{
					i = 0;
					j = 0;
				}
			}
			i++;
		}
		j++;
	}
	valid_or_no(map, row, col);
}
