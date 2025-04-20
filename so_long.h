/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:29:10 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/16 23:15:53 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"

typedef struct s_long
{
	void	*co;
	void	*mlx;
	void	*black;
	void	*player;
	void	*player2;
	void	*m;
	void	*dor;
	void	*open_d;
	void	*enemy1;
	void	*enemy2;
	void	*mlx_win;
	int		row;
	int		col;
	char	**map;
	int		j;
	int		i;
	int		moves_p;
	int		coins;
	int		c;
	int		x;
	int		y;
	int		count_c;
	int		count_p;
	int		count_e;
}t_long;

void	check_arg(int ac, char **av);
char	**fill_map(char **av);
int		count_map(int fd, char *line);
int		ft_count(char **map);
void	check_walls(char **map);
void	check_size(char **map);
void	deff_char(char **map);
void	check_duplicates(t_long a);
int		check_char(char *s, char c);
void	check_e_c_p(char **map, int count_c, int count_e, int count_p);
void	if_valid_path(char **map, int row, int col);
int		ft_strcmp(const char *s1, const char *s2);
void	get_player_pos(char **map, int *jj, int *ii);
void	draw_window(t_long *a);
int		hook_func(int k, t_long *a);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	key_left(t_long *a, int j, int i);
void	key_right(t_long *a, int j, int i);
void	key_up(t_long *a, int j, int i);
void	key_down(t_long *a, int j, int i);
int		close_all(void);
int		nbr_of_coins(char **map, int r, int c);
void	init_t_long(t_long *v);
void	ft_error(void);
void	file_to_images(t_long *a);
void	put_to_window(t_long *a, int j, int i);
void	ft_free(char **array);
void	fill_by_line(char **map, char *line, int fd);
void	ft_error(void);

#endif
