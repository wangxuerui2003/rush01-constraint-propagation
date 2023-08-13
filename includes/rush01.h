/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:03:38 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/13 22:52:49 by wxuerui          ###   ########.fr       */
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

struct tile {
	int num;
	int	*available_nums;
};

struct skyscraper {
	struct clues	clues;
	struct tile		**board;
	int				board_size;
};

void	ft_putstr(char *str);
int	ft_atoi(char *a);
int	ft_isspace(char c);
int	ft_strlen(char *str);
void	ft_putchar(char c);
struct tile	**malloc_board(int board_size);
void	init_board_state(struct tile **board, int board_size);
void	init_tile(struct tile *tile, int board_size);
int	init_game(struct skyscraper *game, char *arg);
void	print_board(struct skyscraper *game);
void	free_game(struct skyscraper *game);
void	free_board(struct tile **board, int board_size);
void	copy_tile(struct tile *dest, struct tile *src, int board_size);
struct tile	**copy_board(struct tile **src, int board_size);

#endif