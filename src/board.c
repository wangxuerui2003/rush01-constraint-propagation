/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:01:55 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/13 22:29:08 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	init_tile(struct tile *tile, int board_size)
{
	int	i;

	tile->num = 0;
	tile->available_nums = malloc(sizeof(int) * board_size);
	i = -1;
	while (++i < board_size)
		tile->available_nums[i] = 1;
}

void	init_board_state(struct tile **board, int board_size)
{
	int	i;
	int	j;

	if (board == NULL)
		return ;
	i = -1;
	while (++i < board_size)
	{
		j = -1;
		while (++j < board_size)
			init_tile(&(board[i][j]), board_size);
	}
}

struct tile	**malloc_board(int board_size)
{
	struct tile	**board;
	int			i;

	board = malloc(board_size * sizeof(struct tile *));
	if (board == NULL)
		return (NULL);
	i = -1;
	while (++i < board_size)
	{
		board[i] = malloc(board_size * sizeof(struct tile));
		if (board[i] == NULL)
			return (NULL);
	}
	return board;
}
