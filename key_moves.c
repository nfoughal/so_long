/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:34:36 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/16 23:11:53 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_left(t_long *a, int j, int i)
{
	if (a->map[j][i + 1] == '1')
		return ;
	if (a->map[j][i + 1] == 'C')
		a->coins--;
	if (a->map[j][i + 1] == 'E')
	{
		if (a->coins == 0)
			exit(0);
		return ;
	}
	a->map[j][i] = '0';
	a->map[j][i + 1] = 'P';
	a->moves_p++;
	write(1, "Moves : ", 9);
	ft_putnbr_fd(a->moves_p, 1);
	write(1, "\n", 1);
}

void	key_right(t_long *a, int j, int i)
{
	if (a->map[j][i - 1] == '1')
		return ;
	if (a->map[j][i - 1] == 'C')
		a->coins--;
	if (a->map[j][i - 1] == 'E')
	{
		if (a->coins == 0)
			exit(0);
		return ;
	}
	a->moves_p++;
	a->map[j][i] = '0';
	a->map[j][i - 1] = 'P';
	write(1, "Moves : ", 9);
	ft_putnbr_fd(a->moves_p, 1);
	write(1, "\n", 1);
}

void	key_up(t_long *a, int j, int i)
{
	if (a->map[j - 1][i] == '1')
		return ;
	if (a->map[j - 1][i] == 'C')
		a->coins--;
	if (a->map[j - 1][i] == 'E')
	{
		if (a->coins == 0)
			exit(0);
		return ;
	}
	a->moves_p++;
	a->map[j][i] = '0';
	a->map[j - 1][i] = 'P';
	write(1, "Moves : ", 9);
	ft_putnbr_fd(a->moves_p, 1);
	write(1, "\n", 1);
}

void	key_down(t_long *a, int j, int i)
{
	if (a->map[j + 1][i] == '1')
		return ;
	if (a->map[j + 1][i] == 'C')
		a->coins--;
	if (a->map[j + 1][i] == 'E')
	{
		if (a->coins == 0)
			exit(0);
		return ;
	}
	a->moves_p++;
	a->map[j][i] = '0';
	a->map[j + 1][i] = 'P';
	write(1, "Moves : ", 9);
	ft_putnbr_fd(a->moves_p, 1);
	write(1, "\n", 1);
}
