/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 19:13:18 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/22 19:17:13 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
**-----------------------------------------------------------------------------
**---------Extra linked list functions not used in the project-----------------
**---------------------------- For reference-----------------------------------
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
** Prints shifted coordinates. Function uses printf.
** ft_putnbr can be used to print numbers instead.
** And ft_putchar or putstr can be used to pring strings.
*/

int print_data_coord(t_tetro *struct_pointer)
{
	int i;
	int *pointer_2;

	i = 0;
	while (struct_pointer)
	{
		pointer_2 = struct_pointer->struct_tetro;
		while (i <= 7)
		{
			printf("%d, ", pointer_2[i]);
			i++;
		}
		i = 0;
		printf("%c\n", struct_pointer->struct_c);
		struct_pointer = struct_pointer->next;
	}
	return (0);
}

/*
** Created a function that counts the numbers of elements that are being
** stored in a linked list.
*/

int struct_element_count(t_tetro *head)
{
	t_tetro *cursor;
	int number_of_elements;

	cursor = head;
	number_of_elements = 0;
	while (cursor != NULL)
	{
		number_of_elements++;
		cursor = cursor->next;
	}
	return (number_of_elements);
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
	while (i < tetro_count)
	{
		pointer_2 = append(pointer_2, characters[i]);
		i++;
	}
	return (pointer_2);
}
