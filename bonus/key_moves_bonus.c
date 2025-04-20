/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:34:36 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/17 18:12:40 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_left(t_long *a, int j, int i)
{
	if (a->map[j][i + 1] == '1')
		return ;
	if (a->map[j][i + 1] == 'C')
		a->coins--;
	if (a->map[j][i + 1] == 'N')
	{
		write(1, "you....lost\n", 13);
		exit(0);
	}
	if (a->map[j][i + 1] == 'E')
	{
		if (a->coins == 0)
			exit(0);
		return ;
	}
	a->map[j][i] = '0';
	a->map[j][i + 1] = 'P';
	a->moves_p++;
}

void	key_right(t_long *a, int j, int i)
{
	if (a->map[j][i - 1] == '1')
		return ;
	if (a->map[j][i - 1] == 'C')
		a->coins--;
	if (a->map[j][i - 1] == 'N')
	{
		write(1, "you....lost\n", 13);
		exit(0);
	}
	if (a->map[j][i - 1] == 'E')
	{
		if (a->coins == 0)
			exit(0);
		return ;
	}
	a->moves_p++;
	a->map[j][i] = '0';
	a->map[j][i - 1] = 'P';
}

void	key_up(t_long *a, int j, int i)
{
	if (a->map[j - 1][i] == '1')
		return ;
	if (a->map[j - 1][i] == 'C')
		a->coins--;
	if (a->map[j - 1][i] == 'N')
	{
		write(1, "you....lost\n", 13);
		exit(0);
	}
	if (a->map[j - 1][i] == 'E')
	{
		if (a->coins == 0)
			exit(0);
		return ;
	}
	a->moves_p++;
	a->map[j][i] = '0';
	a->map[j - 1][i] = 'P';
}

void	key_down(t_long *a, int j, int i)
{
	if (a->map[j + 1][i] == '1')
		return ;
	if (a->map[j + 1][i] == 'C')
		a->coins--;
	if (a->map[j + 1][i] == 'N')
	{
		write(1, "you....lost\n", 13);
		exit(0);
	}
	if (a->map[j + 1][i] == 'E')
	{
		if (a->coins == 0)
			exit(0);
		return ;
	}
	a->moves_p++;
	a->map[j][i] = '0';
	a->map[j + 1][i] = 'P';
}
