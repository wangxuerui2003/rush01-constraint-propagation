/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wangxuerui2003@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:03:38 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/13 20:09:12 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

struct clues {
	int	*up;
	int	*bot;
	int	*left;
	int	*right;
};

struct tile {
	int num;
	int	*available_nums;
};

struct skyscraper {
	struct clues	clues;
	struct tile		*board;
	int				board_size;
};

#endif