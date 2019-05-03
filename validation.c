/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:07:14 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/02 21:31:18 by mbutt            ###   ########.fr       */
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
/*
** Error handler will quit the program if there is no new line at i[4], i[9],
** i[14], or i[19].
*/
/*
int main (void)
{
	int fd;
	int bytes_read;
	char characters[26][21];
	int i;

	i = 0;
	fd = open("./valid_pieces/valid_01", O_RDONLY);
	while((bytes_read = read(fd, characters[i], 21)) >= 20)
	{
		if(characters[i][4] != '\n' || characters[i][9] != '\n')
		{
			printf("Error 1");
			return(0);
		}
		if(characters[i][14] != '\n' || characters[i][19] != '\n')
		{
			printf("Error 2");
			return(0);
		}
		else
		{
			characters[i][20] = '\0';
			i++;
		}
	}
	printf("%s", characters[0]);
	printf("%s", characters[1]);
	printf("%c", characters[1][2]);

	return(0);
}
*/
//using malloc to store pieces in characters
/*
int main (void)
{
	int fd;
	int bytes_read;
	char **characters;
	int i;

	i = 0;
	fd = open("./valid_pieces/valid_01", O_RDONLY);
	while((bytes_read = read (fd, characters)))
}
*/

// breaking the above into a function below.
// Works and gives the file that's read;

void ft_exit(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

char **ft_tetrominoes(int fd)
{
	int bytes_read;
	char **characters;
	int i;
	i = 0;

	characters = (char **)malloc(sizeof(char *) * (26));
	characters[i] = (char *)malloc(sizeof(char) * (20));
	while((bytes_read = read(fd, characters[i], 21)) >= 20)
	{
		if(characters[i][4] != '\n' || characters[i][9] != '\n')
			ft_exit();
		if(characters[i][14] != '\n' || characters[i][19] != '\n')
			ft_exit();
		else 
		{
			characters[i][20] = '\0';
			i++;
			characters[i] = (char *)malloc(sizeof(char) * 20);
		}
	}
//	free(characters[i]);
	return(characters);
}
// ft_tetrominos can now be used to determine if the pieces are valid or not
/*
int ft_dots(char **characters)
{
	static int i_universal;
	int j;
	int dots;
	int fd;
	char **stored_characters;
	if(!i_universal)
		i_universal = 0;
	j = 0;
	dots = 0;
	stored_characters = (char **)malloc(sizeof(char *) * (27));
	stored_characters[i_universal] = (char *)malloc(sizeof(char *) * (21));
	
	stored_characters[i_universal] = ft_strdup(characters[i_universal]);
//	stored_characters[i] = ft_tetrominoes(fd)[i];
//	i++;
	while(characters[i_universal][j])
	{
		if(characters[i_universal][j] == '.')
			dots++;
		j++;
	}
	i_universal++;
	printf("\ndots:|%d|\n", dots);
	return(dots);
}
*/
int is_it_valid(char **characters)
{
	int i;
	int j;
	int dots;
	int hashtags;
//	char **stored_characters;

	i = 0;
	j = 0;
	dots = 0;
	hashtags = 0;
	while(characters[i][j] != '\0')
	{
		while(characters[i][j] != '\0')
		{
			(characters[i][j] == '.') && (dots++);
			(characters[i][j] == '#') && (hashtags++);
			j++;
		}
		if(dots != 12 || hashtags != 4)
			ft_exit();
		printf("dots:|%d|\n", dots);
		printf("hashtags:|%d|\n\n", hashtags);
		i++;
		dots = 0;
		j = 0;
		hashtags = 0;
	}
	return(1);
}
// we have access to characters from ft_tetrominos without calling the function,
// just keeping it commented in case we want to use it because it works well.
char **ft_validation_1(char **characters)
{
	char **stored_characters;
	int i;

	i = 0;

	stored_characters = (char **)malloc(sizeof(char*) * (26));
//	while(stored_characters[i])
//	{
//		stored_characters[i] = ft_strdup(characters[i]);
//		i++;
//	}
		stored_characters[0] = ft_strdup(characters[0]);
//	stored_characters = ft_tetrominoes(characters);

//	printf("Works?\n");
//	printf("This is characters:\n%s\n", characters[0]);
//	printf("This is also characters:\n%s\n", characters[1]);
//	printf("This is stored characters:\n%s\n", stored_characters[0]);
	return(stored_characters);
}
int main (void)
{
	int fd;
	char **characters1;
	char **characters2;
	int dots;

	fd = 0;
	fd = open("./valid_pieces/valid_20", O_RDONLY);
	characters1 = ft_tetrominoes(fd);
//	printf("in main:\n%s", characters1[0]);
//	printf("%s", characters1[1]);
//	printf("%c", characters1[0][3]);

	characters2 = ft_validation_1(characters1);
//	printf("\n\n");
//	printf("printing ft_validation_1:\n");
//	printf("%s\n", characters2[0]);
	printf("%d\n", is_it_valid(characters1));
//	printf("%d\n", ft_dots(characters2));
//	printf("%d\n", ft_dots(characters2));
//	while(1)
//	{

//	}
	return(0);
}

/*
int main (void)
{
	int fd;
	int bytes_read;
	int i;
	char characters[26][21];
	int j;
	int dots;
	int hashtags;

	i = 0;
	j = 0;
	hashtags = 0;
	dots = 0;

	fd = open("./valid_pieces/error_02", O_RDONLY);
	while((bytes_read = read (fd, characters[i], 21)) >= 20)
	{
		characters[i][20] = '\0';
		i++;
	}

	i = 0;
	while(characters[i][j])
	{
		while(characters[i][j])
		{	
			(characters[i][j] == '.') && dots++;
			(characters[i][j] == '#') && hashtags++;
			j++;
		}
		if(dots != 12 && hashtags != 4)
		{
			printf("Error");
			return(0);
		}
		printf("dots:|%d|\n", dots);
		printf("hashtags:|%d|\n", hashtags);
		printf("%s", characters[i]);
		printf("\n");
		printf("single character:|%c|", characters[i][4]);
		i++;
		j = 0;
		dots = 0;
		hashtags = 0;
	}
	return(0);
}
*/
