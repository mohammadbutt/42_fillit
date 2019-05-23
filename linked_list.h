/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 18:35:21 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/22 19:16:46 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "fillit.h"

/*
** Put linked list structures here
*/
typedef struct		s_tetro
{
	void			*struct_tetro;
	char			struct_c;
	struct s_tetro	*next;
}					t_tetro;

/*
** linkedlist.c functions
*/

t_tetro				*create(void *struct_tetro);
t_tetro				*append(t_tetro *head, void *struct_tetro);
t_tetro				*coord_to_struct(int **shifted_coord, int tetro_count);

/*
** ----------------------------------------------------------------------------
** ------------Extra linked list functions not used in the project-------------
** ------------------------------For Reference---------------------------------
*/

void				print_data(t_tetro *struct_pointer);
int					print_data_coord(t_tetro *struct_pointer);
int					struct_element_count(t_tetro *head);
int					print_data_coord(t_tetro *struct_pointer);
t_tetro				*tetro_to_struct(char **characters, int tetro_count);

#endif
