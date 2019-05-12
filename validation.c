/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:21:30 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/12 14:29:30 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** To print the Error message and exit if the tetrominoes are not valid at any
** stage.
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

int initialize_valid(int *i, int *j, int *hash)
{
	i = 0;
	j = 0;
	hash = 0;
	return(0);
}

int is_it_valid(char **characters)
{
	int i;
	int j;
	int hash;

//	i = 0;
//	j = 0;
//	hash = 0;
	initialize_valid(&i, &j, &hash);
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
	return(1);
}

int initialize_xy_coordinates(int *i, int *j, int *k, int *l)
{
	i = 0;
	j = 0;
	k = 0;
	l = 0;

	return(0);
}

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
//	l = 0;
	
	initialize_xy_coordinates(&i, &j, &k, &l);

	coordinates = (int **) malloc(sizeof(int *) * (26));
	coordinates[k] = (int *)malloc(sizeof(int) * (9));
	while(characters[i][j])
	{
//		l = 0;
		while(characters[i][j] != '\0')
		{
			if(characters[i][j] == '#')// && j <= 20)
			{
				coordinates[k][l++] = j%5;
				coordinates[k][l++] = j/5;
			}
			j++;
		}
		i++;
		j = 0;
		l = 0;
		k++;
		coordinates[k] = (int *)malloc(sizeof(int) * (9));
	}
//	free(coordinates[k]); // This needs to be freed after.
	coordinates[k] = NULL;
	return(coordinates);
}

int ft_variable_reset(int *x_min, int *y_min, int *l)
{
	*x_min = 3;
	*y_min = 3;
	*l = 0;

	return(0);
}

int **shift_xy_coordinates(int **coordinates, int x_min, int y_min, int k)
{
//	int x_min;
//	int y_min;
//	int k;
	int l;
	int **shifted_coordinates;

//	k = 0;
	shifted_coordinates = (int **)malloc(sizeof(int *) * (26));
	while(coordinates[k] != NULL)
	{
//		l = 0;
//		x_min = 3;
//		y_min = 3;
		ft_variable_reset(&x_min, &y_min, &l);
		while(l <= 7)
		{
			(coordinates[k][l] <= x_min) && (x_min = coordinates[k][l]);
			l++;
			(coordinates[k][l] <= y_min) && (y_min = coordinates[k][l]);
			l++;
		}
		l = 0;
		shifted_coordinates[k] = (int *)malloc(sizeof(int) * (9));
		while(l <= 7)	
		{
			shifted_coordinates[k][l] = coordinates[k][l] - x_min;
			l++;
			shifted_coordinates[k][l] = coordinates[k][l] - y_min;
			l++;
		}
		k++;
	}
	shifted_coordinates[k] = NULL;	//Is this necessary?
	return(shifted_coordinates);
}

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

int main (void)
{
	int fd;
	char **characters1;

	char **empty_grid;
	int board_size;
	int i;
	int **shifted_coordinates;
	int **coordinates;

	board_size = 4;
	i = 0;
	empty_grid = ft_grid(board_size);

	fd = 0;
//	fd = open("./valid_pieces/valid_21", O_RDONLY);
//	fd = open("./tests/corrects/valid_21", O_RDONLY);
	fd = open("./tests/corrects/valid_05", O_RDONLY);
	if (fd == -1)
		printf("Wrong file name or path\n");
	characters1 = ft_tetrominoes(fd);

	dots_and_hash(characters1);
	is_it_valid(characters1);//, 0, 0, 0);
	
	printf("-------Printing Tetrominoes-------\n");
	while((characters1)[i] != NULL)
	{
		printf("%s\n", (characters1)[i]);
		i++;
	}

	i = 0;

	coordinates = xy_coordinates(characters1, 0, 0, 0);
	printf("-------Printing coordinates-------\n");
	while(coordinates[i]!= NULL)
	{		
		printf("x,y: {%d, ", (coordinates)[i][0]);
		printf("%d}      ", (coordinates)[i][1]);
		printf("x,y: {%d, ", (coordinates)[i][2]);
		printf("%d}      ", (coordinates)[i][3]);
		printf("x,y: {%d, ", (coordinates)[i][4]);
		printf("%d}      ", (coordinates)[i][5]);
		printf("x,y: {%d, ", (coordinates)[i][6]);
		printf("%d}\n\n", (coordinates)[i][7]);
		i++;
	}
	i = 0;


	shifted_coordinates = shift_xy_coordinates(coordinates, 3, 3, 0);
	printf("---Printing shifted coordinates---\n\n");
	while(shifted_coordinates[i] != NULL)
	{
		printf("x,y: {%d, ", (shifted_coordinates)[i][0]);
		printf("%d}      ", (shifted_coordinates)[i][1]);
		printf("x,y: {%d, ", (shifted_coordinates)[i][2]);
		printf("%d}      ", (shifted_coordinates)[i][3]);
		printf("x,y: {%d, ", (shifted_coordinates)[i][4]);
		printf("%d}      ", (shifted_coordinates)[i][5]);
		printf("x,y: {%d, ", (shifted_coordinates)[i][6]);
		printf("%d}\n\n", (shifted_coordinates)[i][7]);	
		i++;
	}
	i = 0;
	
	printf("----------Printing board----------\n");
	while(i < board_size)
	{
		ft_putstr(empty_grid[i]);
		ft_putstr("\n");
		i++;
	}
	printf("\n");

//Printing linked list
/*
	t_tetro *pointer_2;
	pointer_2 = create("Testing");
	pointer_2 = append(pointer_2, "this thing");
	print_data(pointer_2);
*/
/* // Storing strings in variables and using them.	
	char string1[8] = "Testing";
	char string2[12] = "this thing";

	t_tetro *pointer_2;
	pointer_2 = create(string1);
	pointer_2 = append(pointer_2, string2);
	print_data(pointer_2);
*/

	// printing tetrominoes from tetro_to_struct function
	printf("---printing terominoes from tetro_to_struct function---\n");
	t_tetro *pointer_2;
	pointer_2 = tetro_to_struct(characters1);
	print_data(pointer_2);

/*	
	// printing shifted coordinates from coord_to_struct function
	printf("---printing coodinates from coord_to_struct function---\n");
	t_tetro *pointer_2;
	pointer_2 = coord_to_struct(shifted_coordinates);
	print_data_coord(pointer_2);
*/
/*
   	// printing from struct
	printf("---printing tetrominoes from struct---\n");
	t_tetro *pointer_2;
	pointer_2 = create(characters1[0]);
	pointer_2 = append(pointer_2, characters1[1]);
	pointer_2 = append(pointer_2, characters1[2]);
	pointer_2 = append(pointer_2, characters1[3]);
	print_data(pointer_2);
*/
/*
//printing shifted coordinates
	printf("\n---printing shifted coordinates from struct----\n");
	t_tetro *pointer_2;
//	int a[] = {0,1,2,3};
	pointer_2 = create(shifted_coordinates[0]);
	printf("char c: %c\n", pointer_2->struct_c);
	int *b = pointer_2->struct_characters;
	printf("test: %d\n", b[3]);
	print_data_coord(pointer_2);
*/
/*
	pointer_2 = append(pointer_2, shifted_coordinates[0]);
	pointer_2 = append(pointer_2, shifted_coordinates[0]);
	pointer_2 = append(pointer_2, shifted_coordinates[0]);
	pointer_2 = append(pointer_2, shifted_coordinates[0]);
	pointer_2 = append(pointer_2, shifted_coordinates[0]);
	pointer_2 = append(pointer_2, shifted_coordinates[0]);
	pointer_2 = append(pointer_2, shifted_coordinates[0]);
	//print_data_coord(pointer_2);
	
*/

// Returns blanks lines
/*
	t_tetro *pointer_2;
	pointer_2 = create(shifted_coordinates[0]);
	pointer_2 = append(pointer_2, shifted_coordinates[1]);
	print_data(pointer_2);
*/

/*	
 // Gives bus error
	t_tetro *pointer_2;
	pointer_2 = create(tetro_to_struct(&shifted_coordinates[0]));
//	pointer_2 = append(pointer_2,(tetro_to_struct(&shifted_coordinates[1])));
	print_data(pointer_2);
*/
/*
	t_tetro *pointer_2;
	pointer_2 = tetro_to_struct(shifted_coordinates[0]);
	pointer
*/
	return(0);
}

