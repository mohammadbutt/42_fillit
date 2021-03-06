/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:07:14 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/21 20:26:10 by mbutt            ###   ########.fr       */
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

/*
** To print the Error message and exit. This function is created just to save an
** extra line.
*/
void ft_exit(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}
/*
** First step in the project. ft_tetrominoes stores the pieces given by the user
** in a double pointer array. But it also checks if the first, second, third,
** and fourth lines end with a new line.
*/
char **ft_tetrominoes(int fd)
{
	int bytes_read;
	int temp_bytes_read;
	char **characters;
	int i;

	i = 0;
	characters = (char **)malloc(sizeof(char *) * (26));
	characters[i] = (char *)malloc(sizeof(char) * (21));
	while((bytes_read = read(fd, characters[i], 21)) >= 20)
	{
		if(characters[i][4] != '\n' || characters[i][9] != '\n')
			ft_exit();
		if(characters[i][14] != '\n' || characters[i][19] != '\n')
			ft_exit();
		else 
		{
			temp_bytes_read = bytes_read;
			characters[i][20] = '\0';
			characters[++i] = (char *)malloc(sizeof(char) * 21);
		}
	}
	free(characters[i]); // This has to be freed
//	characters[i] = NULL;
	if (temp_bytes_read != 20)
		ft_exit();
	return(characters);
}
// ft_tetrominos can now be used to determine if the pieces are valid or not
/*
*/
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
/* 
** dots_and_hash returns an integer. If there are not 12 . or 4 hastags, then the
** program will print "Error" and exit out of the program. If there are 12 .
** and 4 hashtags then the program will return 1 which means the program can
** now be validated for phase to determine if the pieces entered by the user
** are actually tetrominoes or not.
*/
int dots_and_hash(char **characters)
{
	int i;
	int j;
	int dots;
	int hashtags;

	i = 0;
	j = 0;
	while(characters[i][j])
	{
		dots = 0;
		hashtags = 0;
		while(characters[i][j] != '\0')
		{
			(characters[i][j] == '.') && (dots++);
			(characters[i][j] == '#') && (hashtags++);
			j++;
		}
		if(dots != 12 || hashtags != 4)
			ft_exit();
//		printf("dots:|%d|\n", dots); // Line will be removed
//		printf("hashtags:|%d|\n\n", hashtags); // Line will be removed
		i++;
		j = 0;
	}
//	printf("\ndots_and_hash succesful\n");
	return(1);
}
/*
** is_it_valid function is the last function in determining if the stored
** pieces are valid or not.
** is_it_valid function takes the stored pieces, i, j and hash.
** i, j, and hash are placed within the function to save lines inside the
** function.
** It is important to set i, j, and hash at 0 in the main when this function
** gets called.
*/

int is_it_valid(char **characters, int i, int j, int hash)
{
//	int i;
//	int j;
//	int hash;

//	i = 0;
//	j = 0;
//	hash = 0;
	while(characters[i][j] )//&& j >= 0)
	{
		while(j < 20)
		{
			if (characters[i][j] == '#')
			{
				(characters[i][j+1] == '#') && hash++;
				(characters[i][j+5] == '#') && hash++;
				(characters[i][j-1] == '#') && hash++;
				(characters[i][j-5] == '#') && hash++;
			}
			j++;
			if(j == 20 && (hash == 6 || hash == 8))
				break ;
			if( j == 20 && (hash != 6 || hash != 8))
				ft_exit();
		}
		i++;
		j = 0;
		hash = 0;
	}
//	printf("\nis_it_valid succesful\n");
	return(1);
}
/*
int is_it_valid_one(char **characters)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;

	while(characters[i][j])
	{
		while(characters[i][j])
		{
			if(characters[i][j] == '#')
			{
				if (characters[i][j+1] != '#' || characters[i][j+5] != '#')
					ft_exit();
			}
			j++;
		}
		j = 0;
		i++;
	}
	return(1);
}
*/

int **xy_coordinates(char **characters, int i, int j, int k)
{
//	int i;
//	int j;
//	int k;
	int l;
	int **coordinates;

//	i = 0;
//	j = 0;
//	k = 0;

	coordinates = (int **) malloc(sizeof(int *) * (26));
	coordinates[k] = (int *)malloc(sizeof(int) * (9));
	while(characters[i][j])
	{
		l = 0;
		while(characters[i][j] != '\0')
		{
			if(characters[i][j] == '#')// && j <= 20)
			{
				coordinates[k][l] = j%5;
				l++;
				coordinates[k][l] = j/5;
				l++;
			}
			j++;
		}
		i++;
		j = 0;
		k++;
//		l = 0;
		coordinates[k] = (int *)malloc(sizeof(int) * (9));
	}
//	free(coordinates[k]); // This needs to be freed after.
	coordinates[k] = NULL;
//	printf("coordinates:|%d|",coordinates[0][0]);
	return(coordinates);
}

int **shift_xy_coordinates(int **coordinates)
{
	int x_min;
	int y_min;
	int k;
	int l;

	k = 0;
	while(coordinates[k] != NULL)
	{
		l = 0;
		x_min = 3;
		y_min = 3;
		while(l <= 7)
		{
			(coordinates[k][l] <= x_min) && (x_min = coordinates[k][l]);
			l++;
			(coordinates[k][l] <= y_min) && (y_min = coordinates[k][l]);
			l++;
		}
		l = 0;
		while(l <= 7)	
		{
			coordinates[k][l] = coordinates[k][l] - x_min;
			l++;
			coordinates[k][l] = coordinates[k][l] - y_min;
			l++;
		}
		k++;
	}
	coordinates[k] = NULL;
	return(coordinates);
}
/*
int **shift_xy_coordinates2(int **coordinates)
{
	int i;
	int j;
	int **shifted_coordinates;

	i = 0;
	j = 0;
	shifted_coordinates = (int **)malloc(sizeof(int *) * (26));
	shifted_coordinates[i] = (int *)malloc(sizeof(int) * (9));

	while(coordinates[i][j])
	{
		while(coordinates[i][j] != '\0')
		{
			shifted_coordinates[i][j] = coordinates[i][j];
			j++;
		}
		i++;
		j = 0;
		shifted_coordinates[i] = (int *)malloc(sizeof(int) * (9));
	}

	shifted_coordinates[i] = NULL;
	return(shifted_coordinates);
}
*/
/*
char **coordinates_to_alphabets(int **coordinates)
{
	int i;
	int j;
	int k;
	int l;
	char alpha;

	i = 0;
	j = 0;
	k = 0;
	l = 0;

	alpha = (char **) malloc(sizeof(char *) * (27));
	alpha[i] = (char *) malloc(sizeof(char) * (9));

	while(coordinates[k] != NULL)
	{
		while(l <= 7)
		{
			alpha[i][j] = coordinates[k][l]
		}
	}
}
*/

char **ft_grid(int width)
{
	int height;
	int i;
	int j;
	char **empty_grid;

	i = 0;
	j = 0;
	height = width;
	empty_grid = (char **)malloc(sizeof(char *) * (width + 1));

	while(width != i)
		empty_grid[i++] = (char *)malloc(sizeof(char) * (width + 1));
	i = 0;

	while(height--)
	{
		while(width != j)
			empty_grid[i][j++] = '.';
		empty_grid[i][j] = '\0';
		j = 0;
		i++;
	}
	empty_grid[i] = NULL;
	return(empty_grid);
}

// we have access to characters from ft_tetrominos without calling the function,
// just keeping it commented in case we want to use it because it works well.
/*
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
*/
int main (void)
{
	int fd;
	char **characters1;

	char **empty_grid;
	int board_size;
	int i;

	board_size = 4;
	i = 0;
	empty_grid = ft_grid(board_size);

	fd = 0;
//	fd = open("./valid_pieces/valid_21", O_RDONLY);
//	fd = open("./tests/corrects/valid_21", O_RDONLY);
	fd = open("./tests/corrects/valid_02", O_RDONLY);
	if (fd == -1)
		printf("Wrong file name or path\n");
	characters1 = ft_tetrominoes(fd);
//	array = x_y_coordinates()

//	printf("in main:\n%s", characters1[0]);
//	printf("%s", characters1[1]);
//	printf("%c", characters1[0][3]);

//	characters2 = ft_validation_1(characters1);
//	printf("\n\n");
//	printf("printing ft_validation_1:\n");
//	printf("%s\n", characters2[0]);
//	printf("%d\n", dots_and_hash(characters1));
//	printf("%d\n\n", is_it_valid(characters1, 0, 0, 0));

	dots_and_hash(characters1);
	is_it_valid(characters1, 0, 0, 0);
//	printf("--------------------Validation Succesful\n");
	
	printf("-------Printing Tetrominoes-------\n");
	while((characters1)[i] != NULL)
	{
		printf("%s\n", (characters1)[i]);
		i++;
	}

	i = 0;
	
	printf("-------Printing coordinates-------\n");
	while((xy_coordinates(characters1, 0, 0, 0)[i] != NULL))
	{		
		printf("x,y: {%d, ", (xy_coordinates(characters1, 0, 0, 0)[i][0]));
		printf("%d}      ", (xy_coordinates(characters1, 0, 0, 0)[i][1]));
		printf("x,y: {%d, ", (xy_coordinates(characters1, 0, 0, 0)[i][2]));
		printf("%d}      ", (xy_coordinates(characters1, 0, 0, 0)[i][3]));
		printf("x,y: {%d, ", (xy_coordinates(characters1, 0, 0, 0)[i][4]));
		printf("%d}      ", (xy_coordinates(characters1, 0, 0, 0)[i][5]));
		printf("x,y: {%d, ", (xy_coordinates(characters1, 0, 0, 0)[i][6]));
		printf("%d}\n\n", (xy_coordinates(characters1, 0, 0, 0)[i][7]));
		i++;
	}
	i = 0;

	printf("---Printing shifted coordinates---\n\n");
	while(shift_xy_coordinates(&xy_coordinates(characters1, 0, 0, 0)[i]) != NULL )
	{
		printf("x,y: {%d, ", (shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][0]));
		printf("%d}      ", (shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][1]));
		printf("x,y: {%d, ", (shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][2]));
		printf("%d}      ", (shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][3]));
		printf("x,y: {%d, ", (shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][4]));
		printf("%d}      ", (shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][5]));
		printf("x,y: {%d, ", (shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][6]));
		printf("%d}\n\n", (shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][7]));
		
		i++;
	}
	i = 0;
	printf("---Printing shifted coordinates2---\n\n");
//	while(shift_xy_coordinates2(shift_xy_coordinates(&xy_coordinates(characters1, 0, 0, 0)[i])) != NULL )
//	{
//		printf("x,y: {%d, ", (shift_xy_coordinates2(xy_coordinates(characters1, 0, 0, 0))[i][0]));
//		printf("%d}      ", (shift_xy_coordinates2(shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][1])));
//		printf("x,y: {%d, ", (shift_xy_coordinates2(shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][2])));
//		printf("%d}      ", (shift_xy_coordinates2(shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][3])));
//		printf("x,y: {%d, ", (shift_xy_coordinates2(shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][4])));
//		printf("%d}      ", (shift_xy_coordinates2(shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][5])));
//		printf("x,y: {%d, ", (shift_xy_coordinates2(shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][6])));
//		printf("%d}\n\n", (shift_xy_coordinates2(shift_xy_coordinates(xy_coordinates(characters1, 0, 0, 0))[i][7])));
//		
//		i++;
//	}



	i = 0;
	
	printf("----------Printing board----------\n");
	while(i < board_size)
	{
		ft_putstr(empty_grid[i]);
		ft_putstr("\n");
		i++;
	}

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
