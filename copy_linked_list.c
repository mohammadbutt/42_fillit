/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:59:01 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/18 16:49:37 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Creating a linked list structure called new_node and allocating memory to it
*/

t_tetro	*create(void *struct_tetro)
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
** Taking coordinates of the shifted pieces that are currentlyin a 2D-array,
** and storing them in a linked list structure
*/
t_tetro	*coord_to_struct(int **shifted_coordinates, int tetro_count)
{
	t_tetro *pointer_2;
	int 	i;

	i = 1;
	pointer_2 = create(shifted_coordinates[0]);
	while(i < tetro_count)
	{
		pointer_2 = append(pointer_2, shifted_coordinates[i]);
		i++;
	}
	return(pointer_2);
}

/*
**----------------------------------------------------------------------------
**---------Extra linked list functions not used in the project----------------
**---------------------------- For reference----------------------------------
*/

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
** Prints shifted coordinates
*/

int print_data_coord(t_tetro *struct_pointer)
{
	int i;
	int *pointer_2;

	i = 0;
	while(struct_pointer)
	{
		pointer_2 = struct_pointer->struct_tetro;
		while(i <= 7)
		{
			printf("%d, ", pointer_2[i]);
			i++;
		}
		i = 0;
		printf("%c\n", struct_pointer->struct_c);
		struct_pointer = struct_pointer->next;
	}
	return(0);
}


/*
** Created a function that counts the numbers of elements that are being
** stored in a linked list.
*/

int struct_element_count(t_tetro *head)
{	
	t_tetro *cursor;
	cursor = head;
	int number_of_elements;
	number_of_elements = 0;
	while(cursor != NULL)
	{
		number_of_elements++;
		cursor = cursor->next;
	}
	return(number_of_elements);
}

/*
** Takes tetrominoes that are stored in a 2D-array and stores them in a
** linked list data structure
*/

t_tetro *tetro_to_struct(char **characters, int tetro_count)
{
	t_tetro *pointer_2;
	int i;

	i = 1;
	pointer_2 = create(characters[0]);
	while(i < tetro_count)
	{
		pointer_2 = append(pointer_2, characters[i]);
		i++;
	}
	return(pointer_2);
}
