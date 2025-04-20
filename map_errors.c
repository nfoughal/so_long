/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:33:02 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/16 23:13:45 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_size(char **map)
{
	int	count;
	int	i;

	i = 0;
	count = ft_count(map);
	if (ft_strlen(map[0]) != (ft_strlen(map[count - 1])) + 1)
	{
		write(2, "Error\n", 6);
		ft_free(map);
		exit(1);
	}
	while (i < count - 1)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			write(2, "Error\n", 6);
			ft_free(map);
			exit(1);
		}
		i++;
	}
}

void	deff_char(char **map)
{
	int	count;
	int	i;
	int	j;
	int	len;

	count = ft_count(map);
	j = 0;
	len = (ft_strlen(map[0])) - 1;
	while (j < count - 1)
	{
		i = 0;
		while (i < len)
		{
			if (map[j][i] != 'P' && map[j][i] != 'E'
				&& map[j][i] != 'C' && map [j][i] != '1'
				&& map[j][i] != '0')
			{
				write(2, "Error\n", 6);
				ft_free(map);
				exit(1);
			}
			i++;
		}
		j++;
	}
}

void	check_e_c_p(char **map, int count_c, int count_e, int count_p)
{
	if (count_e != 1 || count_p != 1 || count_c < 1)
	{
		write(2, "Error\n", 6);
		ft_free(map);
		exit(1);
	}
}

void	check_duplicates(t_long a)
{
	size_t	i;
	int		j;

	a.count_p = 0;
	a.count_e = 0;
	a.count_c = 0;
	j = -1;
	while (++j < ((ft_count(a.map)) - 1))
	{
		i = -1;
		while (++i < ((ft_strlen(a.map[0])) - 1))
		{
			if (a.map[j][i] == 'P' || a.map[j][i] == 'E' || a.map[j][i] == 'C')
			{
				if (a.map[j][i] == 'P')
					a.count_p++;
				else if (a.map[j][i] == 'E')
					a.count_e++;
				else if (a.map[j][i] == 'C')
					a.count_c++;
			}
		}
	}
	check_e_c_p(a.map, a.count_c, a.count_e, a.count_p);
}
