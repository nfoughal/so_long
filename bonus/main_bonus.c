/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:26:01 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/18 14:52:17 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_all(void)
{
	exit(0);
	return (0);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	nbr_of_coins(char **map, int r, int c)
{
	int	i;
	int	j;
	int	coins;

	j = 1;
	coins = 0;
	while (j < r)
	{
		i = 1;
		while (i < c)
		{
			if (map[j][i] == 'C')
				coins++;
			i++;
		}
		j++;
	}
	return (coins);
}

void	init_t_long(t_long *v)
{
	v->co = NULL;
	v->mlx = NULL;
	v->black = NULL;
	v->player = NULL;
	v->m = NULL;
	v->dor = NULL;
	v->open_d = NULL;
	v->mlx_win = NULL;
	v->row = 0;
	v->col = 0;
	v->map = NULL;
	v->j = 0;
	v->i = 0;
	v->moves_p = 0;
	v->c = 0;
	v->x = 0;
	v->y = 0;
	v->count_c = 0;
}

int	main(int ac, char **av)
{
	t_long	a;
	char	**map;

	check_arg(ac, av);
	init_t_long(&a);
	a.map = fill_map(av);
	a.mlx = mlx_init();
	a.col = (ft_strlen(a.map[0])) - 1;
	a.row = ft_count(a.map);
	check_size(a.map);
	check_walls(a.map);
	deff_char(a.map);
	check_duplicates(a);
	map = fill_map(av);
	if_valid_path(map, a.row, a.col);
	ft_free(map);
	a.coins = nbr_of_coins(a.map, a.row, a.col);
	file_to_images(&a);
	draw_window(&a);
	mlx_hook(a.mlx_win, 2, 0L, hook_func, &a);
	mlx_hook(a.mlx_win, 17, 0L, close_all, NULL);
	mlx_loop_hook(a.mlx, render_next_frame, &a);
	mlx_loop(a.mlx);
	ft_free(a.map);
	return (0);
}
