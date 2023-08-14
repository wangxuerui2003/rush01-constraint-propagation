/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:43:36 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/14 12:23:50 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

// return 0 for not win yet, 1 for won
int	check_board(struct skyscraper *game)
{
	int	i;

	i = -1;
	while (++i < game->board_size)
	{
		if (check_row(game, i) != 1)
			return (0);
		if (check_col(game, i) != 1)
			return (0);
	}
	return (1);
}

t_vector	inc_pos(t_vector pos, int board_size)
{
	if (pos.col + 1 == board_size)
	{
		pos.row++;
		pos.col = 0;
	}
	else
	{
		pos.col++;
	}
	return (pos);
}

// return 0 for contradiction, 1 for win
int	backtracking(struct skyscraper *game, t_vector pos)
{
	struct cell	**copy;
	int			i;

	if (check_board(game) == 1)
		return (1);
	if (pos.row >= game->board_size)
		return (0);
	copy = malloc_board(game->board_size);
	copy_board(copy, game->board, game->board_size, 1);
	i = -1;
	if (game->board[pos.row][pos.col].num != 0)
	{
		if (backtracking(game, inc_pos(pos, game->board_size)) == 1)
		{
			free_board(copy, game->board_size);
			return (1);
		}
		copy_board(game->board, copy, game->board_size, 0);
		return (0);
	}
	while (++i < game->board_size)
	{
		if (game->board[pos.row][pos.col].available_nums[i] != 0)
		{
			if (modify_cell(game, pos, i + 1, 1) == -1)
			{
				copy_board(game->board, copy, game->board_size, 0);
				continue;
			}
			if (backtracking(game, inc_pos(pos, game->board_size)) == 1)
			{
				free_board(copy, game->board_size);
				return (1);
			}
			copy_board(game->board, copy, game->board_size, 0);
		}
	}
	copy_board(game->board, copy, game->board_size, 0);
	free_board(copy, game->board_size);
	return (0);
}