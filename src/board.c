/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:01:55 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/13 22:52:25 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	free_board(struct tile **board, int board_size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < board_size)
	{
		j = -1;
		while (++j < board_size)
			free(board[i][j].available_nums);
		free(board[i]);
	}
	free(board);
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

struct tile	**copy_board(struct tile **src, int board_size)
{
	struct tile	**board;
	int			i;
	int			j;

	board = malloc_board(board_size);
	i = -1;
	while (++i < board_size)
	{
		j = -1;
		while (++j < board_size)
			copy_tile(&(board[i][j]), &(src[i][j]), board_size);
	}
	return board;
}
