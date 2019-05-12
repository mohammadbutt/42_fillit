/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:59:01 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/12 14:19:01 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Creating a linked list structure and allocating memory to it
*/

t_tetro *create(void *struct_tetro)
{
   t_tetro *new_node;

	new_node = (t_tetro *)malloc(sizeof(t_tetro));
   if(new_node == NULL)
	{
		printf("Error creating a new node.\n");
		ft_exit();
	}

	new_node->struct_tetro = struct_tetro;
	new_node->struct_c = 'A';
	new_node->next = NULL;

	return (new_node);
}

/*
** Creating a structure that appends new pieces to the existing structure
*/
t_tetro *append(t_tetro *head, void *struct_tetro)
{
	t_tetro *cursor;
	t_tetro *new_node;

	cursor = head;
	while(cursor->next != NULL)
		cursor = cursor->next;
	new_node = create(struct_tetro);

	cursor->next = new_node;

	return(head);
}

/*
** prints the tetrominoes that are stored in the linked list
*/
void print_data(t_tetro *struct_pointer)
{
	while (struct_pointer)
	{
		printf("%s\n", struct_pointer->struct_tetro);
		struct_pointer = struct_pointer->next;
	}
}

/*
** DOES NOT WORK. STILL WORKING ON IT. Prints shifted coordinates
*/
int print_data_coord(t_tetro *struct_pointer)
{
	while(struct_pointer)
	{
		printf("%d\n", struct_pointer->struct_coordinates[1]);
//		i++;
		struct_pointer = struct_pointer->next;
	}
	return(0);
}

/*
** Takes tetrominoes that are stored in a 2D-array and stores them in a
** linked list data structure
*/
t_tetro *tetro_to_struct(char **characters)
{
	t_tetro *pointer_2;
	int i;

	i = 1;
	pointer_2 = create(characters[0]);
//	while(i <= 26 && characters[i])
	while(i <= 3)
	{
		pointer_2 = append(pointer_2, characters[i]);
		i++;
	}
	return(pointer_2);
}

/*
** Taking coordinates of the shifted pieces that are currentlyin a 2D-array,
** and storing them in a linked list structure
*/
t_tetro	*coord_to_struct(int **shifted_coordinates)
{
	t_tetro *pointer_2;
	int i;

	i = 1;
	pointer_2 = create(shifted_coordinates[0]);
	while(i <= 5)
	{
		pointer_2 = append(pointer_2, shifted_coordinates[i]);
		i++;
	}
	return(pointer_2);
}

