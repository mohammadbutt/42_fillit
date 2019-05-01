/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:47:41 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/01 16:16:04 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> // for printf
/*
** We can assume that pieces are valid.
** pieces that are valid are stored in a 2D array as numbers. Not linked list.
** We will use malloc twice. Malloc once to malloc number of pieces. Malloc
** the second time to malloc each character in a 2d array.
*/

int main (void)
{
	int fd;
	int ret1;
	char stored_grid[21];
	char placeholder[20 + 1];
	char *one_line;
	fd = open("valid1.txt", O_RDONLY);

	while((ret1 = read(fd, placeholder, 20)) == 20)
	{
		ft_strcpy(stored_grid, placeholder);
//		break;
	}

	printf("%s", stored_grid);
	printf("%s", placeholder);

	return(0);
}
