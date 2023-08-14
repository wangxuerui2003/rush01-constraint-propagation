/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:03:38 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/14 12:27:15 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

struct clues {
	int	*up;
	int	*bot;
	int	*left;
	int	*right;
};

struct cell {
	int num;
	int	*available_nums;
};

typedef struct vector {
	int	row;
	int	col;
}	t_vector;

struct skyscraper {
	struct clues	clues;
	struct cell		**board;
	int				board_size;
};

void	ft_putstr(char *str);
int	ft_atoi(char *a);
int	ft_isspace(char c);
int	ft_strlen(char *str);
void	ft_putchar(char c);
struct cell	**malloc_board(int board_size);
void	init_board_state(struct cell **board, int board_size);
void	init_cell(struct cell *cell, int board_size);
int	init_game(struct skyscraper *game, char *arg);
void	print_board(struct skyscraper *game);
void	free_game(struct skyscraper *game);
void	free_board(struct cell **board, int board_size);
void	copy_cell(struct cell *dest, struct cell *src, int board_size, int need_malloc);
void	copy_board(struct cell **dest, struct cell **src, int board_size, int need_malloc);
int	update_cell(struct skyscraper *game, t_vector pos);
int	modify_cell(struct skyscraper *game, t_vector pos, int num, int do_update);
int	check_board(struct skyscraper *game);
int	check_row(struct skyscraper *game, int row);
int	check_col(struct skyscraper *game, int col);
int	backtracking(struct skyscraper *game, t_vector pos);
void	basic_constraints(struct skyscraper *game);

#endif