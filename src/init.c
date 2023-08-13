/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:28:50 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/13 22:32:38 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	get_board_size(char *arg)
{
	int	i;
	int	size;

	size = 0;
	i = -1;
	while (arg[++i] != '\0')
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			size++;
	}
	if (size % 4 != 0)
		return (-1);
	return (size / 4);
}

void	init_clues(struct clues *clues, int board_size, char *arg)
{
	int	i;
	int	num_index;

	clues->up = malloc(sizeof(int) * board_size);
	clues->bot = malloc(sizeof(int) * board_size);
	clues->left = malloc(sizeof(int) * board_size);
	clues->right = malloc(sizeof(int) * board_size);
	i = -1;
	num_index = 0;
	while (++i < ft_strlen(arg))
	{
		while (ft_isspace(arg[i]))
			i++;
		if (num_index < board_size)
			clues->up[num_index % board_size] = ft_atoi(arg + i);
		else if (num_index < board_size * 2)
			clues->bot[num_index % board_size] = ft_atoi(arg + i);
		else if (num_index < board_size * 3)
			clues->left[num_index % board_size] = ft_atoi(arg + i);
		else
			clues->right[num_index % board_size] = ft_atoi(arg + i);
		num_index++;
		while (arg[i] >= '0' && arg[i] <= '9')
			i++;
	}
}

int	check_valid_clues(struct clues *clues, int board_size)
{
	int	i;

	i = -1;
	while (++i < board_size)
		if (clues->up[i] < 1 || clues->up[i] > board_size)
			return (0);
	i = -1;
	while (++i < board_size)
		if (clues->bot[i] < 1 || clues->bot[i] > board_size)
			return (0);
	i = -1;
	while (++i < board_size)
		if (clues->left[i] < 1 || clues->left[i] > board_size)
			return (0);
	i = -1;
	while (++i < board_size)
		if (clues->right[i] < 1 || clues->right[i] > board_size)
			return (0);
	return (1);
}

struct tile	**init_board(int board_size)
{
	struct tile	**board;

	board = malloc_board(board_size);
	init_board_state(board, board_size);
	return (board);
}

int	init_game(struct skyscraper *game, char *arg)
{
	game->board_size = get_board_size(arg);
	if (game->board_size == -1)
		return (-1);
	init_clues(&(game->clues), game->board_size, arg);
	if (!check_valid_clues(&(game->clues), game->board_size))
		return (-1);
	game->board = init_board(game->board_size);
	if (game->board == NULL)
		return (-1);
	return (0);
}
