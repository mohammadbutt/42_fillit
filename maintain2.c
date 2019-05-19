/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintain2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:18:08 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/18 19:53:42 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function coord_to_alpha takes coordinates that are shifted to the top left,
** and an empty grid. Then the function places alphabets onto the empty_grid
** at the shifted_coordinates location.
*/

char	**alpha_on_grid(int *shifted_coord, char **empty_grid)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i <= 7)
	{
		x = shifted_coord[i];
		y = shifted_coord[i + 1];
		empty_grid[y][x] = shifted_coord[8];
		i = i + 2;
	}
	return (empty_grid);
}

/*
** Function that prints the alphabets placed onto the grid.
*/

void	**ft_print(char **empty_grid)
{
	int i;

	i = 0;
	while (empty_grid[i] != NULL)
	{
		ft_putstr(empty_grid[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

/*
** Function that will shift the tetromino by x and y. Adding 1 to x will move
** the tetromino to the right by 1 place. And adding 1 to y will move the
** the tetromino down by 1 place.
** Tetrominoes will be shifted when the pieces collide with each other,
** or go over board uring backtracking.
*/

int		*shift_tetro(int *shifted_coord, int x, int y)
{
	int i;

	i = 0;
	while (i <= 7)
	{
		shifted_coord[i] = shifted_coord[i] + x;
		i++;
		shifted_coord[i] = shifted_coord[i] + y;
		i++;
	}
	return (shifted_coord);
}

/*
** Functions that detect collision with the board size first and then pieces.
** Pieces cannot land on top of each other and the pieces cannot be placed
** outside the board/grid.
** Functions return 0 if there's no collision, or 1 if it detects collision.
** Function 1 - Collision with the pieces.
** Function 2 - Collision with the board.
*/

int		collision(char **empty_grid, int *shifted_coord, int board_size)
{
	int max;
	int i;
	int x;
	int y;

	max = 0;
	initialize_with_zero(&i, &x, &y);
	while (i <= 7)
	{
		(shifted_coord[i] >= max) && (max = shifted_coord[i]);
		i++;
	}
	if (max >= board_size)
		return (1);
	i = 0;
	while (i <= 7)
	{
		x = shifted_coord[i];
		y = shifted_coord[i + 1];
		if (empty_grid[y][x] != '.')
			return (1);
		i = i + 2;
	}
	return (0);
}

/*
** remove_tetro function will remove the previous tetromino, if the
** current piece collided with another piece on collided with the board
** in each iteration.
*/

void	remove_tetro(char **empty_grid, int *shifted_coord)
{
	int i;
	int x;
	int y;

	initialize_with_zero(&i, &x, &y);
	while (i <= 7)
	{
		x = shifted_coord[i];
		y = shifted_coord[i + 1];
		empty_grid[y][x] = '.';
		i = i + 2;
	}
}
