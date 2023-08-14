/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:29:10 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/14 09:39:19 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	print_row(struct cell *row, int board_size)
{
	int	i;

	i = -1;
	while (++i < board_size)
	{
		ft_putchar(row[i].num + '0');
		ft_putchar(' ');
	}
}

void	print_clues(int *clues, int board_size)
{
	int	i;

	i = -1;
	ft_putchar(' ');
	while (++i < board_size)
	{
		ft_putchar(' ');
		ft_putchar(clues[i] + '0');
	}
	ft_putchar('\n');
}

void	print_board(struct skyscraper *game)
{
	int	i;

	print_clues(game->clues.up, game->board_size);
	i = -1;
	while (++i < game->board_size)
	{
		ft_putchar(game->clues.left[i] + '0');
		ft_putchar(' ');
		print_row(game->board[i], game->board_size);
		ft_putchar(game->clues.right[i] + '0');
		ft_putchar('\n');
	}
	print_clues(game->clues.bot, game->board_size);
}