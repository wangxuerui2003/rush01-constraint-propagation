/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:47:54 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/14 12:23:10 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	init_cell(struct cell *cell, int board_size)
{
	int	i;

	cell->num = 0;
	cell->available_nums = malloc(sizeof(int) * board_size);
	i = -1;
	while (++i < board_size)
		cell->available_nums[i] = 1;
}

void	init_board_state(struct cell **board, int board_size)
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
			init_cell(&(board[i][j]), board_size);
	}
}

void	copy_cell(struct cell *dest, struct cell *src, int board_size, int need_malloc)
{
	int			i;

	dest->num = src->num;
	if (need_malloc)
		dest->available_nums = malloc(sizeof(int) * board_size);
	i = -1;
	while (++i < board_size)
		dest->available_nums[i] = src->available_nums[i];
}