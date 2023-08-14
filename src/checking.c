/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:40:21 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/14 11:44:26 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_col_dup(struct skyscraper *game, int col)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->board_size)
	{
		if (game->board[i][col].num == 0)
			continue ;
		j = -1;
		while (++j < game->board_size)
			if (j != i && (game->board[i][col].num == game->board[j][col].num))
				return (1);
	}
	return (0);
}

// return -1 for temporary ok, 0 for not ok, 1 for win col
int	check_col(struct skyscraper *game, int col)
{
	int	i;
	int	see;
	int	highest;

	if (check_col_dup(game, col))
		return (0);
	i = -1;
	while (++i < game->board_size)
	{
		if (game->board_size - game->board[i][col].num + i + 1 < game->clues.up[col]) // if tower too tall
			return (0);
		else if (game->board_size - game->board[game->board_size - i - 1][col].num + i + 1 < game->clues.bot[col])
			return (0);
	}
	see = 1;
	highest = game->board[0][col].num;
	i = -1;
	while (++i < game->board_size)
	{
		if (game->board[i][col].num == 0)
			return (-1);
		if (game->board[i][col].num > highest)
		{
			highest = game->board[i][col].num;
			see++;
		}
	}
	if (see != game->clues.up[col])
		return (0);
	see = 1;
	highest = game->board[game->board_size - 1][col].num;
	i = game->board_size;
	while (--i >= 0)
	{
		if (game->board[i][col].num == 0)
			return (-1);
		if (game->board[i][col].num > highest)
		{
			highest = game->board[i][col].num;
			see++;
		}
	}
	if (see != game->clues.bot[col])
		return (0);
	return (1);
}

int	check_row_dup(struct skyscraper *game, int row)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->board_size)
	{
		if (game->board[row][i].num == 0)
			continue ;
		j = -1;
		while (++j < game->board_size)
			if (j != i && (game->board[row][i].num == game->board[row][j].num))
				return (1);
	}
	return (0);
}

// return -1 for temporary ok, 0 for not ok, 1 for win row
int	check_row(struct skyscraper *game, int row)
{
	int	i;
	int	see;
	int	highest;

	if (check_row_dup(game, row))
		return (0);
	i = -1;
	while (++i < game->board_size)
	{
		if (game->board_size - game->board[row][i].num + i + 1 < game->clues.left[row]) // if tower too tall
			return (0);
		else if (game->board_size - game->board[row][game->board_size - i - 1].num + i + 1 < game->clues.right[row])
			return (0);
	}
	see = 1;
	highest = game->board[row][0].num;
	i = -1;
	while (++i < game->board_size)
	{
		if (game->board[row][i].num == 0)
			return (-1);
		if (game->board[row][i].num > highest)
		{
			highest = game->board[row][i].num;
			see++;
		}
	}
	if (see != game->clues.left[row])
		return (0);
	see = 1;
	highest = game->board[row][game->board_size - 1].num;
	i = game->board_size;
	while (--i >= 0)
	{
		if (game->board[row][i].num == 0)
			return (-1);
		if (game->board[row][i].num > highest)
		{
			highest = game->board[row][i].num;
			see++;
		}
	}
	if (see != game->clues.right[row])
		return (0);
	return (1);
}
