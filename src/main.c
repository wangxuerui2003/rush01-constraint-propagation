/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:50:23 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/13 22:34:08 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

// Helper functions to implement

// parse input from ac and av
// allocate 2d array
// free 2d array
// copy 2d array
// check if a row is valid
// check if a column is valid
// check win
// eliminates the impossible available numbers on the board
// fill in the "must be" numbers on the board
// printing board

// helper helper functions
// free a tile
// ft_atoi


int main(int ac, char **av)
{
	struct skyscraper	game;

	if (ac != 2) {
		ft_putstr("Usage: ./rush01 \"col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right\"\n");
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

	// TODO: Start backtracking the answer, every recursion saves the current state of the board for future use if there is a contradiction

	// Print out the board
	print_board(&game);

	system("leaks -q rush01");
	return (0);
}