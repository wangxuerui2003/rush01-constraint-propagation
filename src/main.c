/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:50:23 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/14 12:27:32 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

// Helper functions to implement

// check if a row is valid
// check if a column is valid
// check win
// eliminates the impossible available numbers on the board
// fill in the "must be" numbers on the board

void	free_game(struct skyscraper *game)
{
	free_board(game->board, game->board_size);
	free(game->clues.up);
	free(game->clues.bot);
	free(game->clues.left);
	free(game->clues.right);
}

int main(int ac, char **av)
{
	struct skyscraper	game;

	if (ac != 2) {
		ft_putstr("Usage: ./rush01 \"<clues>\"\n");
		return 1;
	}

	// Parse input
	// Allocate 2d array of the board, each element is a struct of cell number and possible numbers
	if (init_game(&game, av[1]) != 0)
	{
		ft_putstr("Error\n");
		return 2;
	}

	// TODO: Do the first round of constraints
	basic_constraints(&game);
	print_board(&game);

	// TODO: Start backtracking the answer, every recursion saves the current state of the board for future use if there is a contradiction
	if (backtracking(&game, (t_vector){0, 0}) == 0)
	{
		ft_putstr("Error\n");
		return 3;
	}
	// Print out the board
	print_board(&game);

	// Free memory
	free_game(&game);

	return (0);
}