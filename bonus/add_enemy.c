/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:07:28 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/17 20:02:12 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_enemy_pos(char **map, int *jj, int *ii)
{
	int	i;
	int	j;
	int	count;
	int	len;
	int	k;

	j = 1;
	k = 0;
	len = (ft_strlen(map[0])) - 1;
	count = ft_count(map);
	while (j < count - 1)
	{
		i = 0;
		while (i < len)
		{
			if (map[j][i] == 'N')
			{
				*jj = j;
				*ii = i;
				return ;
			}
			i++;
		}
		j++;
	}
}

int	render_next_frame(t_long *a)
{
	int			i;
	int			j;
	static int	k;

	get_player_pos(a->map, &j, &i);
	if (k == 2000)
	{
		mlx_put_image_to_window(a->mlx,
			a->mlx_win, a->player, i * 100, j * 100);
	}
	else if (k == 4000)
	{
		mlx_put_image_to_window(a->mlx, a->mlx_win, a->black, i * 100, j * 100);
		k = 0;
	}
	k++;
	return (1);
}

void	get_player_pos(char **map, int *jj, int *ii)
{
	int	i;
	int	j;
	int	count;
	int	len;
	int	k;

	j = 1;
	k = 0;
	len = (ft_strlen(map[0])) - 1;
	count = ft_count(map);
	while (j < count - 1)
	{
		i = 0;
		while (i < len)
		{
			if (map[j][i] == 'P')
			{
				*jj = j;
				*ii = i;
				return ;
			}
			i++;
		}
		j++;
	}
}
