/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraints_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:50:26 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/14 11:39:22 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

// number of available numbers left in the cell
int	num_availables_in_cell(struct cell *cell, int board_size)
{
	int	i;
	int	num_avail;

	num_avail = 0;
	i = -1;
	while (++i < board_size)
	{
		if (cell->available_nums[i] != 0)
			num_avail++;
	}
	return (num_avail);
}

int	find_avail(struct cell *cell, int board_size)
{
	int	i;

	i = -1;
	while (++i < board_size)
	{
		if (cell->available_nums[i] != 0)
			return (i + 1);
	}
	return (-1);
}

int	update_cell(struct skyscraper *game, t_vector pos)
{
	int			i;
	struct cell	*cell;
	int			num_avail;

	cell = &(game->board[pos.row][pos.col]);
	i = -1;
	while (++i < game->board_size)
	{
		if (game->board[i][pos.col].num != 0)
			cell->available_nums[game->board[i][pos.col].num - 1] = 0;
		if (game->board[pos.row][i].num != 0)
			cell->available_nums[game->board[pos.row][i].num - 1] = 0;
	}
	num_avail = num_availables_in_cell(cell, game->board_size);
	if (num_avail == 0)
		return (-1);
	else if (num_avail == 1)
	{
		if (modify_cell(game, pos, find_avail(cell, game->board_size), 0) == -1)
			return (-1);
		return (1);
	}
	return (0);
}
