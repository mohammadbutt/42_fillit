/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:31:22 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/18 12:08:34 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <limits.h>
# include "./libft/libft.h"

/*
** Put macros here if any
*/
# define USAGE	"usage: ./fillit filename"


/* 
** Put protptypes here if any
*/
/*
** Storing tetrominoes and validating
*/
void 	ft_exit(void); // OK
//int		ft_variable_reset(int *x_min, int *y_min, int *l);
char	**ft_tetrominoes(int fd); // OK
int		dots_and_hash(char **characters); // OK
int		initialize_valid(int *i, int *j, int *hash); // OK
int		is_it_valid(char **characters); // OK
int		initialize_xy_coordinates(int *i, int *j, int *k, int *l); // OK
int		**xy_coordinates(char **characters, int i, int j, int k); // OK
int		ft_variable_reset(int *xmin, int *y_min, int *l); // OK
int		**shift_xy_coordinates(int **coordinates, int x_min, int y_min, int k); // OK

/*
** Creating grid, placing tetrominoes in the form of alphabets
** on the board, clearing tetrominoes from grid, detecting collision
**, and duplicating coordinates
*/
int		tetro_count(char **characters);
char	**ft_grid(int width);
void	ft_swap(int *x, int *y);
int		**swap_xy_coord(int **shifted_coordinates);
char	**alpha_on_grid(int *shifted_coordinates, char **empty_grid);
//void	**ft_print(int board_size, char **empty_grid);
void	**ft_print(char **empty_grid);
//int		*xy_shift(int *shift, int x, int y);
//int		*shift_tetro(int *current_position, int x, int y);
int		*shift_tetro(int *shifted_coordinates, int x, int y);
int		box_collision(int *shifted_coordinates, int board_size);
int		tetro_collision(char **empty_grid, int *shifted_coordinates);
int		collision(char **empty_grid, int *shifted_coordinates, int board_size);
void	clear_tetro(char **empty_grid, int *shifted_coordinates);
int		duplicate_coordinates(int *dest, int *shifted_coordinates);
//int	place_next_piece(int *shifted_coordinates, char **empty_grid, int board_size, int i);
int 	place_next_piece(int *shifted_coordinates, char **empty_grid, int board_size);
//int	fill_board(int *shifted_coordinates, char **empty_grid, int board_size, int i);
int		fill_board(int *shifted_cooridnates, char **empty_grid, int board_size);
char 	**solve_tetro(char **empty_grid, int **shifted_coordinates, int board_size);

/*
**	Backtracking solver functions
*/

//int 	help_solve(char **empty_grid, int *shifted_coordinates, int **shifted_coordinates_2, int board_size);
//int		solve_tet(char **empty_grid, int **shifted_coordinates_2, int board_size);
int 	solve_tet_one(char **empty_grid, int *shifted_coordinates, int **shifted_coordinates_2, int board_size);
//int 	solve_driver(int fd);


// -- 19 valid pieces in a single array

/*
** Put structures here and functions created for linked lists
*/
typedef struct s_tetro
{
	void 	*struct_tetro;
//	int		*struct_coordinates;
	char 	struct_c; 				/*carries alphabets*/
	struct 	s_tetro *next;
}			t_tetro;

t_tetro		*create(void *struct_tetro);
t_tetro		*append(t_tetro *head, void *struct_tetro);
void		print_data(t_tetro *struct_pointer);
int			print_data_coord(t_tetro *struct_pointer);
int			struct_element_count(t_tetro *head);
//int			print_data_coord(t_tetro *struct_pointer);
t_tetro		*tetro_to_struct(char **characters, int tetro_count);
t_tetro		*coord_to_struct(int **shifted_coordinates, int tetro_count);// Using this

int		help_solve(char **empty_grid, int *shifted_coordinates, t_tetro *stack, int board_size);
int		solve_tet(char **empty_grid, t_tetro *stack, int board_size);
int		solve_driver(int fd);
#endif
