/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:31:22 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/22 18:23:51 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "linked_list.h"

/*
** Define macros here
*/

# define USAGE	"usage: ./fillit filename"

/*
** Put protptypes here if any
*/

/*
** Backtracker.c functions with linked lists
*/
int		help_solve(char **grid, int *shifted_coord, t_tetro *stack, int board);
int		solve_tet(char **grid, t_tetro *stack, int board_size);
int		solve_driver2(int **shifted_coordinates, int tet_count);
int		solve_driver1(int fd);
void	free_stack_coord(t_tetro *stack);

/*
** coordinate.c functions
*/
int		**xy_coord(char **characters, int i, int j, int k);
int		ft_variable_reset(int *xmin, int *y_min, int *l);
int		ft_x_min(int *coord);
int		ft_y_min(int *coord);
int		**shift_xy_coord(int **coord, int x_min, int y_min, int k);

/*
** free_functions.c functions
*/
void	free_2d_char(char **empty_grid);
void	free_2d_int(int **coordinates);

/*
** libft.c functions
*/
void	ft_strdel(char **string);
void	ft_memdel(void **char_int);
void	ft_putstr(char const *s);
char	*ft_strcpy(char *dst, const char *src);
void	ft_bzero(char *string);

/*
** maintain1.c functions
*/
void	ft_exit(void);
int		tetro_count(char **characters);
char	**ft_grid(int width);
int		duplicate_coord(int *dest, int *shifted_coord);

/*
** maintain2.c functions
*/
char	**alpha_on_grid(int *shifted_coord, char **empty_grid);
void	**ft_print(char **empty_grid);
int		*shift_tetro(int *shifted_coord, int x, int y);
int		collision(char **empty_grid, int *shifted_coord, int board_size);
void	remove_tetro(int *shifted_coord, char **empty_grid);

/*
** valid.c functions
*/
int		initialize_with_zero(int *a, int *b, int *c, int *d);
char	**ft_tetrominoes(int fd, int bytes_read, int temp_bytes_read, int i);
int		dots_and_hash(char **characters);
int		hash_touch(char **characters, int i, int j, int hash);
int		is_it_valid(char **characters);

#endif
