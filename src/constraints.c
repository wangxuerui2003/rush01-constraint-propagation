/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:39:35 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/14 12:29:44 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	update_board(struct skyscraper *game)
{
	int	i;
	int	j;
	int	res;

	i = -1;
	while (++i < game->board_size)
	{
		j = -1;
		while (++j < game->board_size)
		{
			if (game->board[i][j].num != 0)
				continue ;
			res = update_cell(game, (t_vector){i, j});
			if (res == -1) // contradiction
				return (-1);
			else if (res == 1) // re-update the board when there is a number filled in
			{
				i = -1;
				break ;
			}
		}
	}
	return (0);
}

// return -1 for contradiction when modify, 0 for ok
int	modify_cell(struct skyscraper *game, t_vector pos, int num, int do_update)
{
	int	i;

	game->board[pos.row][pos.col].num = num;
	if (!check_row(game, pos.row) || !check_col(game, pos.col))
	{
		game->board[pos.row][pos.col].num = 0;
		return (-1);
	}
	i = -1;
	while (++i < game->board_size)
		game->board[pos.row][pos.col].available_nums[i] = 0;
	if (do_update && update_board(game) == -1)
		return (-1);
	return (0);
}

void	basic_constraints(struct skyscraper *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->board_size)
	{
		if (game->clues.up[i] == game->board_size)
		{
			j = -1;
			while (++j < game->board_size)
			{
				game->board[j][i].num = j + 1;
			}
		}
		else if (game->clues.up[i] == 1)
			game->board[0][i].num = game->board_size;
	}
	i = -1;
	while (++i < game->board_size)
	{
		if (game->clues.bot[i] == game->board_size)
		{
			j = -1;
			while (++j < game->board_size)
			{
				game->board[game->board_size - j - 1][i].num = j + 1;
			}
		}
		else if (game->clues.bot[i] == 1)
			game->board[game->board_size - 1][i].num = game->board_size;
	}
	i = -1;
	while (++i < game->board_size)
	{
		if (game->clues.left[i] == game->board_size)
		{
			j = -1;
			while (++j < game->board_size)
			{
				game->board[i][j].num = j + 1;
			}
		}
		else if (game->clues.left[i] == 1)
			game->board[i][0].num = game->board_size;
	}
	i = -1;
	while (++i < game->board_size)
	{
		if (game->clues.right[i] == game->board_size)
		{
			j = -1;
			while (++j < game->board_size)
			{
				game->board[i][game->board_size - j - 1].num = j + 1;
			}
		}
		else if (game->clues.right[i] == 1)
			game->board[i][game->board_size - 1].num = game->board_size;
	}
}