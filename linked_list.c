/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:59:01 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/21 13:23:25 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Creating a linked list structure called new_node and allocating memory to it
*/

t_tetro		*create(void *struct_tetro)
{
	t_tetro	*new_node;

	new_node = (t_tetro *)malloc(sizeof(t_tetro));
	if (new_node == NULL)
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

t_tetro		*append(t_tetro *head, void *struct_tetro)
{
	t_tetro *cursor;
	t_tetro *new_node;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	new_node = create(struct_tetro);
	cursor->next = new_node;
	return (head);
}

/*
** Taking coordinates of the shifted pieces that are currentlyin a 2D-array,
** and storing them in a linked list structure
*/

t_tetro		*coord_to_struct(int **shifted_coordinates, int tetro_count)
{
	t_tetro *pointer_2;
	int		i;

	i = 1;
	pointer_2 = create(shifted_coordinates[0]);
	while (i < tetro_count)
	{
		pointer_2 = append(pointer_2, shifted_coordinates[i]);
		i++;
	}
	return (pointer_2);
}
