/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:01:55 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/14 12:23:32 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	free_board(struct cell **board, int board_size)
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

struct cell	**malloc_board(int board_size)
{
	struct cell	**board;
	int			i;

	board = malloc(board_size * sizeof(struct cell *));
	if (board == NULL)
		return (NULL);
	i = -1;
	while (++i < board_size)
	{
		board[i] = malloc(board_size * sizeof(struct cell));
		if (board[i] == NULL)
			return (NULL);
	}
	return board;
}

void	copy_board(struct cell **dest, struct cell **src, int board_size, int need_malloc)
{
	int			i;
	int			j;

	i = -1;
	while (++i < board_size)
	{
		j = -1;
		while (++j < board_size)
			copy_cell(&(dest[i][j]), &(src[i][j]), board_size, need_malloc);
	}
}
