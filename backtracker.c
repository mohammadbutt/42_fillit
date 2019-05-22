/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:19:18 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/22 13:42:57 by mbutt            ###   ########.fr       */
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

	//t_tetro *temp;
	board_size = 4;
	stack = coord_to_struct(shifted_coordinates, tet_count);
//	free_2d_int(shifted_coordinates);
	empty_grid = ft_grid(board_size);
	while ((solve_tet(empty_grid, stack, board_size)) == 0)
	{
	//	free_grid(empty_grid, board_size); // Function in maintain1.c
//		free_grid(empty_grid); // Function in maintain1.c
		free_2d_char(empty_grid); // Function in free_function.c
		board_size++;
		empty_grid = ft_grid(board_size);
	}
	ft_print(empty_grid);
	free_stack_coord(stack);
	free_2d_char(empty_grid);
	free(shifted_coordinates);
	return (1);
}
//int		dot_and_hash(char **characters);
int		solve_driver1(int fd)
{
	char	**characters;
	int		tet_count;
	int		**coordinates;
	int		**shifted_coordinates;
	int		**min;
	characters = ft_tetrominoes(fd, 0, 0, 0); 	// no leaks
	is_it_valid(characters); 					// no leaks
	tet_count = tetro_count(characters);		// no leaks
	printf("%d\n", tet_count);					// no leaks
	coordinates = xy_coord(characters, 0, 0, 0);// Maybe ok -free coord at end
	free_2d_char(characters);
	shifted_coordinates = shift_xy_coord(coordinates, 3, 3, 0);
	free_2d_int(coordinates);
	return (solve_driver2(shifted_coordinates, tet_count));
//	return(tet_count);
//	return(1);
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
