/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:44:30 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/17 22:29:08 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	file_to_images(t_long *a)
{
	a->black = mlx_xpm_file_to_image(a->mlx,
			"./bonus/xpm_bonus/black.xpm", &a->x, &a->y);
	a->co = mlx_xpm_file_to_image(a->mlx,
			"./bonus/xpm_bonus/collectible.xpm", &a->x, &a->y);
	a->player = mlx_xpm_file_to_image(a->mlx,
			"./bonus/xpm_bonus/player.xpm", &a->x, &a->y);
	a->m = mlx_xpm_file_to_image(a->mlx,
			"./bonus/xpm_bonus/tile111.xpm", &a->x, &a->y);
	a->dor = mlx_xpm_file_to_image(a->mlx,
			"./bonus/xpm_bonus/door.xpm", &a->x, &a->y);
	a->open_d = mlx_xpm_file_to_image(a->mlx,
			"./bonus/xpm_bonus/open_door.xpm", &a->x, &a->y);
	a->enemy1 = mlx_xpm_file_to_image(a->mlx,
			"./bonus/xpm_bonus/enemy1.xpm", &a->x, &a->y);
	if (!a->black || !a->co || !a->player || !a->m
		|| !a->dor || !a->open_d || !a->enemy1)
		ft_error();
	a->mlx_win = mlx_new_window(a->mlx, a->col * 100, a->row * 100, "so_long");
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
	else if (a->map[j][i] == 'N')
		mlx_put_image_to_window(a->mlx, a->mlx_win,
			a->enemy1, i * 100, j * 100);
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

void	string_put(t_long *a)
{
	int		i;
	int		j;
	char	s[50];
	char	*b;
	char	*t;

	i = 0;
	j = 0;
	b = "Movement count: ";
	while (b[i])
		s[j++] = b[i++];
	t = ft_itoa(a->moves_p);
	i = 0;
	while (t[i])
		s[j++] = t[i++];
	s[j] = '\0';
	mlx_string_put(a->mlx, a->mlx_win, 10, 10, 0xFFFFFF, s);
	free(t);
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
	string_put(a);
	return (1);
}
