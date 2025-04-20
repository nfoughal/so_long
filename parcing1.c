/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:24:26 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/15 19:37:14 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_and_last(char **map, int length, int count)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (map[0][i] != '1' || map[count][i] != '1')
		{
			write(2, "Error\n", 6);
			ft_free(map);
			exit(1);
		}
		i++;
	}
}

void	check_walls(char **map)
{
	int	count;
	int	length;
	int	j;

	j = -1;
	count = ft_count(map) - 1;
	length = ft_strlen(map[0]);
	first_and_last(map, length, count);
	while (++j < count)
	{
		if (map[j][0] != '1' || map[j][length - 2] != '1')
		{
			write(2, "Error\n", 6);
			ft_free(map);
			exit(1);
		}
	}
}
