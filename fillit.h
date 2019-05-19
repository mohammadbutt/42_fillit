/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:31:22 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/18 19:48:12 by mbutt            ###   ########.fr       */
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
void 	ft_exit(void);
char	**ft_tetrominoes(int fd);
int		dots_and_hash(char **characters);
int		initialize_with_zero(int *i, int *j, int *hash);
int		hash_touch(char **characters, int i, int j, int hash);
int		is_it_valid(char **characters);
int		initialize_xy_coord(int *i, int *j, int *k, int *l);
int		**xy_coord(char **characters, int i, int j, int k);
int		ft_variable_reset(int *xmin, int *y_min, int *l);
int		**xy_min(int **coord, int k, int l, int x);
int		**shift_xy_coord(int **coord, int x_min, int y_min, int k);

/*
** Creating grid, placing tetrominoes in the form of alphabets
** on the board, clearing tetrominoes from grid, detecting collision
** and duplicating coordinates
*/
int		tetro_count(char **characters);
char	**ft_grid(int width);
char	**alpha_on_grid(int *shifted_coord, char **empty_grid);
void	**ft_print(char **empty_grid);
int		*shift_tetro(int *shifted_coord, int x, int y);
int		collision(char **empty_grid, int *shifted_coord, int board_size);
void	remove_tetro(char **empty_grid, int *shifted_coord);
int		duplicate_coord(int *dest, int *shifted_coord);

/*
** Put structures here and functions created for linked lists
*/
typedef struct s_tetro
{
	void 	*struct_tetro;
	char 	struct_c;
	struct 	s_tetro *next;
}			t_tetro;

/*
** Backtracking functions with linked lists
*/

int	help_solve(char **grid, int *shifted_coord, t_tetro *stack, int board_size);
int	solve_tet(char **grid, t_tetro *stack, int board_size);
int	solve_driver2(int **shifted_coordinates, int tet_count);
int	solve_driver1(int fd);

t_tetro		*create(void *struct_tetro);
t_tetro		*append(t_tetro *head, void *struct_tetro);
t_tetro		*coord_to_struct(int **shifted_coord, int tetro_count);

/*
** --------------------------------------------------------------------------
** ------------Extra linked list functions not used in the project-----------
** ------------------------------For Reference-------------------------------
*/

void		print_data(t_tetro *struct_pointer);
int			print_data_coord(t_tetro *struct_pointer);
int			struct_element_count(t_tetro *head);
int			print_data_coord(t_tetro *struct_pointer);
t_tetro		*tetro_to_struct(char **characters, int tetro_count);

#endif
