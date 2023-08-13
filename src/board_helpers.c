/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:47:54 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/13 22:51:21 by wxuerui          ###   ########.fr       */
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

void	copy_tile(struct tile *dest, struct tile *src, int board_size)
{
	int			i;

	dest->num = src->num;
	dest->available_nums = malloc(sizeof(int) * board_size);
	i = -1;
	while (++i < board_size)
		dest->available_nums[i] = src->available_nums[i];
}