/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:31:22 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/09 18:51:18 by mbutt            ###   ########.fr       */
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
int		ft_variable_reset(int *x_min, int *y_min, int *l);
char	**ft_tetrominoes(int fd);
int		dot_and_hash(char **characters);
int		is_it_valid(char **characters, int i, int j, int hash);
int		**xy_coordinates(char **characters, int i, int j, int k);
int		**shift_xy_coordinates(int **coordinates, int x_min, int y_min, int k);
char	**ft_grid(int width);


// -- 19 valid pieces in a single array

/*
** Put structures here and functions created for linked lists
*/
typedef struct s_tetro
{
	void *characters;
	char c; 				/*carries alphabets*/
	struct s_tetro *next;
}		t_tetro;

t_tetro		*create(void *characters);
t_tetro		*append(t_tetro *head, void *characters);
void		print_data(t_tetro *pname);

#endif
