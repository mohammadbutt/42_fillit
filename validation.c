/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:21:30 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/15 17:22:02 by mbutt            ###   ########.fr       */
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
	characters = (char **)malloc(sizeof(char *) * (27));
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

/*
** Above functions are done validating a tetromino. If a tetromino piece
** made it this far then the tetromino is valid.
*/

/*
** Tuning tetrominoes into coordinates.
** Index of a tetromino % 5 gives x.
** Same index of the tetromino / 5 gives y.
** We modulo and divide by 5 because each line has 5 elements from 0 to 19.
** For instance 15th place % 5 is 0, And 15th place / 5 is 3. This gives us
** x = 0 and y 3.
*/
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

	coordinates = (int **) malloc(sizeof(int *) * (27));
//	coordinates[k] = (int *)malloc(sizeof(int) * (9));
	while(characters[i][j])
	{
//		l = 0;
		coordinates[k] = (int *)malloc(sizeof(int) * (9));
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
//		coordinates[k] = (int *)malloc(sizeof(int) * (9));
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

/*
** Coordinates are shifted to the top left location.
** x_min and y_min are calucluated first and then subtracted from
** the original coordinates.
*/

int **shift_xy_coordinates(int **coordinates, int x_min, int y_min, int k)
{
//	int x_min;
//	int y_min;
//	int k;
	char c;
	int l;
	int **shifted_coordinates;
	
	c = 'A';
//	k = 0;
	shifted_coordinates = (int **)malloc(sizeof(int *) * (27));
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
		shifted_coordinates[k] = (int *)malloc(sizeof(int) * (10));
		while(l <= 7)	
		{
			shifted_coordinates[k][l] = coordinates[k][l] - x_min;
			l++;
			shifted_coordinates[k][l] = coordinates[k][l] - y_min;
			l++;
		}
		shifted_coordinates[k][l] = c;
		c++;
		l++;
		k++;
	}
	shifted_coordinates[k] = NULL;	//Is this necessary?
	return(shifted_coordinates);
}
/*
** Function that counts the number of tetrominoes that are stored
** in a 2D-array.
*/

int tetro_count(char **coordinates)
{
	int i; 

	i = 0;
	if(coordinates[i])
		while(coordinates[i] != NULL)
			i++;
	return(i-1);
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

/*
** Function that takes the size and generates a grid.
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

/*
** Function swap x and y.
*/

void ft_swap(int *x, int *y)
{
	int temp_x;
	temp_x = *x;
	*x = *y;
	*y = temp_x;
}

int **swap_xy_coord(int **shifted_coordinates)
{
	int temp;
	int k;
	int l;
	int **new_shifted_coord;

	temp = 0;
	k = 0;
	l = 0;
	new_shifted_coord = (int **)malloc(sizeof(int *) * 27);
	new_shifted_coord[k] = (int *)malloc(sizeof(int) * 10);

	while(shifted_coordinates[k] != NULL)
	{
		while(l <= 8)
		{
			new_shifted_coord[k][l] = shifted_coordinates[k][l];
			l++;
		}
		l = 0;
		k++;
		new_shifted_coord[k] = (int *)malloc(sizeof(int) * 10);
	}
	new_shifted_coord[k] = NULL;
	k = 0;
	while(new_shifted_coord[k] != NULL)
	{
		ft_swap(&new_shifted_coord[k][0], &new_shifted_coord[k][1]);
		ft_swap(&new_shifted_coord[k][2], &new_shifted_coord[k][3]);
		ft_swap(&new_shifted_coord[k][4], &new_shifted_coord[k][5]);
		ft_swap(&new_shifted_coord[k][6], &new_shifted_coord[k][7]);
		k++;
	}
//	new_shifted_coord[k] = NULL; 
	return(new_shifted_coord);
}

/*
** Function coord_to_alpha takes coordinates that are shifted to the top left,
** and an empty grid. Then the function places alphabets onto the empty_grid
** at the shifted_coordinates location.
*/

//char **alpha_on_grid(int *new_shifted_coord, char **empty_grid)
char **alpha_on_grid(int *shifted_coordinates, char **empty_grid)
{
	int i;
	int j;
	char c;

	i = 0;
	j = 0;
	c = 'A';

	while(i <= 7)
	{
//		empty_grid[new_shifted_coord[i+1]][new_shifted_coord[i]] = new_shifted_coord[8];
		empty_grid[shifted_coordinates[i+1]][shifted_coordinates[i]] = shifted_coordinates[8];
		i = i + 2;
	}
	return(empty_grid);
}

/*
** Function that prints the alphabets placed onto the grid.
*/

//void **ft_print(char **empty_grid)
void **ft_print(char **empty_grid)
{
	int i;
	i = 0;
	
	while(empty_grid[i] != NULL)
	{
		ft_putstr(empty_grid[i]);
		write(1, "\n", 1);
		i++;
	}

	return(0);
}
/*
** Function that will shift the tetromino by x and y. Adding 1 to x will move
** the tetromino to the right by 1 place. And adding 1 to y will move the
** the tetromino down by 1 place.
** Tetrominoes will be shifted when the pieces collide with each other.
*/
//int		*shift_tetro(int *current_position, int x, int y )
int			*shift_tetro(int *shifted_coordinates, int x, int y)
{
	int i;
	
	i = 0;
	while(i <= 7)
	{
//		current_position[i] = current_position[i] + x;
		shifted_coordinates[i] = shifted_coordinates[i] + x;
		i++;
//		current_position[i] = current_position[i] + y;
		shifted_coordinates[i] = shifted_coordinates[i] + y;
		i++;
	}
	return(shifted_coordinates);
	//	return(current_position);
}

/*
** Functions that detect collision with the board size first and then pieces.
** Pieces cannot land on top of each other and the pieces cannot be placed
** outside the board/grid.
** Functions return 0 if there's no collision, or 1 if it detects collision.
** Function 1 - Collision with the pieces.
** Function 2 - Collision with the board.
*/ 
int box_collision(int *shifted_coordinates, int board_size)
{
	int max;
	int i;

	max = 0;
	i = 0;
	
	while(i<= 7)
	{
		(shifted_coordinates[i] >= max) && (max = shifted_coordinates[i]);
		i++;
	}
	printf("\nx_max:|%d|\n", max);// this can be removed
	printf("y_max:|%d|\n", max); // this can be removed

	if(max >= board_size)
		return(1);
	return(0);
}

int tetro_collision(char **empty_grid, int *shifted_coordinates)
{
	int i;
	i = 0;

	while(i <=7)
	{
		if(empty_grid[shifted_coordinates[i+1]][shifted_coordinates[i]] != '.')
			return(1);
		i = i +2;
	}
	return(0);
}

int collision(char **empty_grid, int *shifted_coordinates, int board_size)
{
	int max;
	int i;

	max = 0;
	i = 0;

	while(i <= 7)
	{
		(shifted_coordinates[i] >= max) && (max =shifted_coordinates[i]);
		i++;
	}
	if (max >= board_size)
		return (1);
	i = 0;
	while(i <= 7)
	{
		if(empty_grid[shifted_coordinates[i+1]][shifted_coordinates[i]] != '.')
			return(1);
		i = i+2;
	}
	return(0);
}

/*
** clear_tetro function will clear the tetromino piece if it was not placed
** properly for some reason. 
*/

void clear_tetro(char **empty_grid, int *shifted_coordinates)
{
	int i;
	i = 0;

	while(i <= 7)
	{
		empty_grid[shifted_coordinates[i+1]][shifted_coordinates[i]] = '.';
		i = i + 2;
	}
}

/*
** Clearing grid. Grid will be cleared out if no solution is reached during
** backtracking. Clearning the grid allows the backtracking algorithm to start
** fresh again by placing the first tetromino on the board again, but this time
** a different piece will be placed on the board.
*/

//-------------------------MAIN--------------------------------
int main (void)
{
	int fd;
	char **characters1;

	char **empty_grid;
	int board_size;
	int i;
	int **shifted_coordinates;
	int **coordinates;
	int t_count;
	int **swap_coord;

	char **alpha_grid;


	board_size = 4;
	i = 0;
	empty_grid = ft_grid(board_size);

	fd = 0;
//	fd = open("./valid_pieces/valid_21", O_RDONLY);
//	fd = open("./tests/fails/error_02", O_RDONLY);
	fd = open("./tests/corrects/valid_06", O_RDONLY);
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
//-----------------------------------------------------------
	printf("---Printing number of tetrominoes---\n");
	printf("%d\n", tetro_count(characters1));

//-----------------------------------------------------------
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
//-------------------------------------------------------------
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
		printf("%d}", (shifted_coordinates)[i][7]);
		printf("%c\n\n", (shifted_coordinates)[i][8]);
		i++;
	}
//--------------------------------------------------------------

	i = 0;
	swap_coord = swap_xy_coord(shifted_coordinates);
	printf("----------Printing swapped x and y-----------------\n");
	while(shifted_coordinates[i] != NULL)
	{
		printf("y,x: {%d, ", (swap_coord)[i][0]);
		printf("%d}      ", (swap_coord)[i][1]);
		printf("y,x: {%d, ", (swap_coord)[i][2]);
		printf("%d}      ", (swap_coord)[i][3]);
		printf("y,x: {%d, ", (swap_coord)[i][4]);
		printf("%d}      ", (swap_coord)[i][5]);
		printf("y,x: {%d, ", (swap_coord)[i][6]);
		printf("%d}", (swap_coord)[i][7]);
		printf("%c\n\n", (swap_coord)[i][8]);
		i++;
	}


//--------------------------------------------------------------	
	i = 0;
	printf("----------Printing board----------\n");
	while(i < board_size)
	{
//		ft_putstr(empty_grid[i]);
//		ft_putstr("\n");
		printf("%s", empty_grid[i]);
		printf("\n");
		i++;
	}
	i = 0;
	printf("\n\n");
/*
	char c = 'a';
	int j = 0;

	while(i <= 3)
	{
		while(j <= 3)
		{
			empty_grid[i][j] = c;
			c++;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while(i < board_size)
	{
//		ft_putstr(empty_grid[i]);
//		ft_putstr("\n");
		printf("%s", empty_grid[i]);
		printf("\n");
		i++;
	}
	printf("\n");
*/
	alpha_grid = alpha_on_grid(shifted_coordinates[0], empty_grid);

	printf("%c\n", empty_grid[0][0]);
	printf("%c\n", empty_grid[1][0]);
	printf("%c", empty_grid[2][0]);
	printf("%c", empty_grid[2][1]);
	printf("\n\n");
	printf("---new test---\n");
//	printf("%c", empty_grid[*swap_coord[0]][*swap_coord[1]]);
//	printf("%c\n", empty_grid[*swap_coord[2]][*swap_coord[3]]);
//	printf("%c", empty_grid[*swap_coord[4]][*swap_coord[5]]);

	printf("\nalpha_grid\n\n");



	printf("%s\n", alpha_grid[0]);
	printf("%s\n", alpha_grid[1]);
	printf("%s\n", alpha_grid[2]);
	printf("%s\n", alpha_grid[3]);


	printf("\nprinting the print function\n");
	ft_print(empty_grid);

	printf("\n---printing shifted x and y---\n");

	int *new_position = shift_tetro(shifted_coordinates[2], 2, 0);
	char **test = alpha_on_grid(new_position, empty_grid);
	new_position = shift_tetro(shifted_coordinates[1], 0, 3);
	test = alpha_on_grid(new_position, empty_grid);
	ft_print(test);

	printf("board_size:|%d|\n", board_size);
	printf("%d\n", box_collision(shifted_coordinates[1], board_size));

	clear_tetro(test, shifted_coordinates[2]);
	ft_print(test);
//	printf("%c\n", empty_grid[swap_coord[2]][swap_coord[3]]);
//	printf("%c\n", empty_grid[swap_coord[4]][swap_coord[5]]);
//	printf("%c\n", empty_grid[swap_coord[6]][swap_coord[7]]);



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

/*	
	// printing tetrominoes from tetro_to_struct function
	// printing struct_element_count
	printf("---printing terominoes from tetro_to_struct function and count---\n");
	t_tetro *pointer_2;
	int 	pointer_3;
	pointer_2 = tetro_to_struct(characters1, tetro_count(characters1));
	pointer_3 = struct_element_count(pointer_2);
	print_data(pointer_2);
	printf("\n");

	printf("%d", pointer_3);
//	print_data(pointer_3);
*/
	
	// printing shifted coordinates from coord_to_struct function
	printf("---printing coodinates from coord_to_struct function---\n");
	t_count = tetro_count(characters1);
	t_tetro *pointer_2;
	pointer_2 = coord_to_struct(shifted_coordinates, t_count);
/*
	int *pointer_3;
	i = 0;
	pointer_3 = pointer_2->next->struct_tetro;
	printf("\n\n");
	while(i < 8)
	{
		printf("%d\n", pointer_3[i]);
		i++;
	}
*/
	print_data_coord(pointer_2);
//	print_data(pointer_2);
//	print_data_coord(pointer_2);
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

