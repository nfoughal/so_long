/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:44:30 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/17 23:43:39 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_to_images(t_long *a)
{
	a->black = mlx_xpm_file_to_image(a->mlx,
			"./xpm/black.xpm", &a->x, &a->y);
	a->co = mlx_xpm_file_to_image(a->mlx,
			"./xpm/collectible.xpm", &a->x, &a->y);
	a->player = mlx_xpm_file_to_image(a->mlx, "./xpm/player.xpm", &a->x, &a->y);
	a->m = mlx_xpm_file_to_image(a->mlx, "./xpm/tile111.xpm", &a->x, &a->y);
	a->dor = mlx_xpm_file_to_image(a->mlx, "./xpm/door.xpm", &a->x, &a->y);
	a->open_d = mlx_xpm_file_to_image(a->mlx,
			"./xpm/open_door.xpm", &a->x, &a->y);
	a->mlx_win = mlx_new_window(a->mlx, a->col * 100, a->row * 100, "so_long");
	if (!a->black || !a->co || !a->player || !a->m || !a->dor || !a->open_d)
		ft_error();
}

void	put_to_window(t_long *a, int j, int i)
{
	if (a->map[j][i] == '1')
		mlx_put_image_to_window(a->mlx, a->mlx_win, a->m, i * 100, j * 100);
	else if (a->map[j][i] == 'E' && a->coins != 0)
		mlx_put_image_to_window(a->mlx, a->mlx_win, a->dor, i * 100, j * 100);
	else if (a->map[j][i] == 'P')
		mlx_put_image_to_window(a->mlx, a->mlx_win, a->player,
			i * 100, j * 100);
	else if (a->map[j][i] == 'C')
		mlx_put_image_to_window(a->mlx, a->mlx_win, a->co, i * 100, j * 100);
	else if (a->map[j][i] == '0')
		mlx_put_image_to_window(a->mlx, a->mlx_win, a->black, i * 100, j * 100);
	else if (a->map[j][i] == 'E' && a->coins == 0)
		mlx_put_image_to_window(a->mlx, a->mlx_win, a->open_d,
			i * 100, j * 100);
}

void	draw_window(t_long *a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < a->row)
	{
		i = 0;
		while (i < a->col)
		{
			put_to_window(a, j, i);
			i++;
		}
		j++;
	}
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

int	hook_func(int k, t_long *a)
{
	int	i;
	int	j;

	if (k == 53)
		exit(0);
	get_player_pos(a->map, &j, &i);
	if (k == 124)
		key_left(a, j, i);
	if (k == 123)
		key_right(a, j, i);
	if (k == 126)
		key_up(a, j, i);
	if (k == 125)
		key_down(a, j, i);
	draw_window(a);
	return (1);
}
