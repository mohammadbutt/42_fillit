/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:47:41 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/01 18:23:26 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"
/*
** We can assume that pieces are valid.
** pieces that are valid are stored in a 2D array as numbers. Not linked list.
** We will use malloc twice. Malloc once to malloc number of pieces. Malloc
** the second time to malloc each character in a 2d array.
** convert binary to decimal
*/
/*
int main (void)
{
	
	int fd;
	int ret1;
	int node;
	char **stored_grid;
	char placeholder[20 + 1];

	node = 0;
//	char *one_line;

	stored_grid = (char **)malloc(sizeof(char *) * (3 + 1));
	stored_grid[0] = (char *)malloc(sizeof(char) * (20));
	stored_grid[1] = (char *)malloc(sizeof(char) * (20));
	stored_grid[2] = (char *)malloc(sizeof(char) * (20));

	fd = open("valid1.txt", O_RDONLY);

	while((ret1 = read(fd, placeholder, 20 + 1)) == 20 + 1)
	{
		ft_strcpy(stored_grid[node], placeholder);
		node++;
//		break;
	}

//	stored_grid[node] = NULL;

	printf("%s", stored_grid[0]);
	printf("%s", stored_grid[1]);

	printf("%s", stored_grid[2]);

	printf("%s", placeholder);

	return(0);
}
*/
// using get_next_line to read the file

int main (void)
{
	int fd1;
	int ret1;
	char *one_line;

	fd1 = open("valid1.txt", O_RDONLY);

	while((ret1 = get_next_line(fd1, &one_line) > 0))
	{
		printf("%s", one_line);
		printf("\n");
		free(one_line);
	}

	return(0);
}

/*
int main (void)
{
	int fd1;
	int ret1;
	char *one_line;
	char placeholder[20 + 1];

	fd1 = open("valid1.txt", O_RDONLY);

	while(read(fd1, placeholder, 20 + 1))
	{
		printf("%s,", placeholder);
		printf("\n");
	}
}
*/
