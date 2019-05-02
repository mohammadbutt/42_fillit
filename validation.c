/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:07:14 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/02 10:21:26 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
// Reads a files and prints the last piece successfuly
int main (void)
{
	int fd;
	int bytes_read;
	char characters_read[21];
	fd = open("./valid_pieces/valid_20", O_RDONLY);

	while((bytes_read = read(fd, characters_read, 21)) >= 20)
	{
		characters_read[20] = '\0';
	}

	printf("%s", characters_read);
	printf("%c", characters_read[1]);

	return(0);
}
*/
/*
// Reads a file and shows first two pieces
int main (void)
{
	int fd;
	int bytes_read;
	char characters_read[2][21];
	int i;

	i = 0;
	fd = open("./valid_pieces/valid_20", O_RDONLY);

	while((bytes_read = read(fd, characters_read[i], 21)) >= 20)
	{
		characters_read[i][20] = '\0';
		i++;
	}
	printf("%s", characters_read[0]);
	printf("%s", characters_read[1]);
	printf("%c", characters_read[1][2]);

	return(0);
}
*/

/* 
**Because we can only have 26 pieces at most, we can use characters[26].
** characters[26][21] will allocate memory for 26 pieces.
** Each piece of 26 can store upto 21 characters.
*/
/*
int main (void)
{
	int fd;
	int bytes_read;
	char characters_read[26][21];
	int i;

	i = 0;

	fd = open("./valid_pieces/valid_20", O_RDONLY);

	while((bytes_read = read (fd, characters_read[i], 21)) >= 20)
	{
		characters_read[i][20] = '\0';
		i++;
	}
	printf("%s", characters_read[0]);
	printf("%s", characters_read[1]);
	printf("%c", characters_read[1][2]);

	return(0);
}
*/

int main (void)
{
	int fd;
	int bytes_read;
	char characters_read[26][21];
	int i;

	i = 0;

	fd = open("./valid_pieces/valid_20", O_RDONLY);

	while((bytes_read = read(fd, characters_read[i], 21)) >= 20)
	{
		characters_read[i][20] = '\0';
		i++;
	}
	printf("%s", characters_read[0]);
	printf("%s", characters_read[1]);
	printf("%c", characters_read[1][2]);

	return(0);
}
