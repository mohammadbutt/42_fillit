/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:31:22 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/14 20:50:04 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <limits.h>
# include "./libft/libft.h"

/* 
** Put protptypes here if any
*/
void 	ft_exit(void);
//int		ft_variable_reset(int *x_min, int *y_min, int *l);
char	**ft_tetrominoes(int fd);
int		dots_and_hash(char **characters);
int		initialize_valid(int *i, int *j, int *hash);
int		is_it_valid(char **characters);
int		initialize_xy_coordinates(int *i, int *j, int *k, int *l);
int		**xy_coordinates(char **characters, int i, int j, int k);
int		ft_variable_reset(int *xmin, int *y_min, int *l);
int		**shift_xy_coordinates(int **coordinates, int x_min, int y_min, int k);
int		tetro_count(char **characters);
char	**ft_grid(int width);
void	ft_swap(int *x, int *y);
int		**swap_xy_coord(int **shifted_coordinates);
char	**alpha_on_grid(int *shifted_coordinates, char **empty_grid);
//void	**ft_print(int board_size, char **empty_grid);
void	**ft_print(char **empty_grid);
int		*xy_shift(int *shift, int x, int y);
int		detect_collision(char **empty_grid, int *tetro);

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
t_tetro		*coord_to_struct(int **shifted_coordinates, int tetro_count);

#endif
