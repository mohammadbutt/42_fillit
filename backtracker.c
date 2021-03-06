/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:19:18 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/05 11:13:52 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Functions and algorithms that solves the tetromino and places
** tetrominoes in the smallest sqaure possible.
** This is where a lot of the previously created functions will be used.
** --------------------------- Backtracking-----------------------------
*/

int		help_solve(char **grid, int *shifted_coord, t_tetro *stack, int board)
{
	if (collision(grid, shifted_coord, board) == 0)
	{
		alpha_on_grid(shifted_coord, grid);
//		ft_print(grid); /*prints grid*/
//		sleep(1);  /*adds a pause*/
//		ft_putstr("\n"); /*adds a newline*/
		if (solve_tet(grid, stack->next, board) == 1)
		{
			free(shifted_coord);
			return (1);
		}
		remove_tetro(shifted_coord, grid);
	}
	return (0);
}

int		solve_tet(char **grid, t_tetro *stack, int board_size)
{
	int *shifted_coord;
	int x;
	int y;

	y = -1;
	shifted_coord = (int *)malloc(sizeof(int) * 9);
	if (stack == NULL)
	{
		free(shifted_coord);
		return (1);
	}
	while (++y < board_size)
	{
		x = 0;
		while (x < board_size)
		{
			duplicate_coord(shifted_coord, stack->struct_tetro);
			shift_tetro(shifted_coord, x, y);
			if (help_solve(grid, shifted_coord, stack, board_size) == 1)
				return (1);
			x++;
		}
	}
	free(shifted_coord);
	return (0);
}

int		solve_driver2(int **shifted_coordinates, int tet_count)
{
	int		board_size;
	char	**empty_grid;
	t_tetro *stack;

	board_size = 2;
	stack = coord_to_struct(shifted_coordinates, tet_count);
	empty_grid = ft_grid(board_size);
	while ((solve_tet(empty_grid, stack, board_size)) == 0)
	{
		free_2d_char(empty_grid);
		board_size++;
		empty_grid = ft_grid(board_size);
	}
	ft_print(empty_grid);
	free_stack_coord(stack);
	free_2d_char(empty_grid);
	free(shifted_coordinates);
	return (1);
}

int		solve_driver1(int fd)
{
	char	**characters;
	int		tet_count;
	int		**coordinates;
	int		**shifted_coordinates;

	characters = ft_tetrominoes(fd, 0, 0, 0);
	is_it_valid(characters);
	tet_count = tetro_count(characters);
	coordinates = xy_coord(characters, 0, 0, 0);
	free_2d_char(characters);
	shifted_coordinates = shift_xy_coord(coordinates, 3, 3, 0);
	free_2d_int(coordinates);
	return (solve_driver2(shifted_coordinates, tet_count));
}

/*
** Function that frees up the stack of tetrominoes before
** it can be allocated memory again.
*/

void	free_stack_coord(t_tetro *stack)
{
	t_tetro *temp;

	temp = NULL;
	while (stack)
	{
		temp = stack;
		stack = temp->next;
		free(temp->struct_tetro);
		free(temp);
	}
}
