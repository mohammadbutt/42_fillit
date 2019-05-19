/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:21:30 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/18 20:03:13 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** To print the Error message and exit if the tetrominoes are not valid at any
** stage.
*/
/*
void ft_exit(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}
*/
/*
** First step in the project. ft_tetrominoes stores the pieces given by
** the user in a double pointer array. But it also checks if the first,
** second, third, and fourth lines end with a new line.
*/
/*
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
	free(characters[i]);
	characters[i] = NULL;
	if (temp_bytes_read != 20)
		ft_exit();
	return(characters);
}
*/
/* 
** dots_and_hash returns an integer. If there are not 12 dots or 4 hastags,
** then the program will print "Error" and exit out of the program.
** If there are 12 dots and 4 hashtags then the program will return 1
** which means the program can now be validated for the next phase to determine
** if the pieces entered by the user are actually tetrominoes or not.
*/
/*
int dots_and_hash(char **characters)
{
	int i;
	int j;
	int dots;
	int hashtags;

	i = 0;
	j = 0;
	while(characters[i])
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
	return(1);
}
*/
/*
** is_it_valid function is the last function in determining if the stored
** pieces are valid or not.
** is_it_valid function takes the stored pieces, i, j and hash.
** i, j, and hash are placed within the function to save lines inside the
** function.
** It is important to set i, j, and hash at 0 in the main when this function
** gets called.
*/
/*
int initialize_hash_touch(int *i, int *j, int *hash)
{
	*i = 0;
	*j = 0;
	*hash = 0;
	return(0);
}

int hash_touch(char **characters, int i, int j, int hash)
{
	initialize_hash_touch(&i, &j, &hash);
	while(characters[i])
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
*/
/*
int is_it_valid(char **characters)
{
	dots_and_hash(characters);
	hash_touch(characters, 0, 0, 0);
	return(1);
}
*/
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
/*
int initialize_xy_coord(int *i, int *j, int *k, int *l)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*l = 0;

	return(0);
}
*/
/*
int **xy_coord(char **characters, int i, int j, int k)
{
	int l;
	int **coordinates;
	
	initialize_xy_coord(&i, &j, &k, &l);
	coordinates = (int **) malloc(sizeof(int *) * (27));
	while(characters[i])
	{
		coordinates[k] = (int *)malloc(sizeof(int) * (9));
		while(characters[i][j] != '\0')
		{
			if(characters[i][j] == '#')
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
	}
	coordinates[k] = NULL;
	return(coordinates);
}
*/
/*
int ft_variable_reset(int *x_min, int *y_min, int *l)
{
	*x_min = 3;
	*y_min = 3;
	*l = 0;
	return(0);
}
*/
/*
int **xy_min(int **coord, int k, int l, int x)
{
	int **min;
	int y;

	y = 1;
	min = (int **)malloc(sizeof(int *) * (27));
	while(coord[k] != NULL)
	{
		min[k] = (int *)malloc(sizeof(int) * 2);
		ft_variable_reset(&min[k][x], &min[k][y], &l);
		while(l <= 7)
		{
			if(coord[k][l] <= min[k][x])
				min[k][x] = coord[k][l];
			l++;
			if(coord[k][l] <= min[k][y])
				min[k][y] = coord[k][l];
			l++;
		}
		k++;
	}
	return(min);
}
*/
/*
** Coordinates are shifted to the top left location.
** x_min and y_min are calucluated first and then subtracted from
** the original coordinates.
*/
/*
int **shift_xy_coord(int **coord, int x_min, int y_min, int k)
{
	char c;
	int l;
	int **shifted_coord;
	
	c = 'A';
	shifted_coord = (int **)malloc(sizeof(int *) * (27));
	while(coord[k] != NULL)
	{
		ft_variable_reset(&x_min, &y_min, &l);
		shifted_coord[k] = (int *)malloc(sizeof(int) * (9));
		while(l <=7)
		{
			x_min = xy_min(coord, 0, 0, 0)[k][0];
			y_min = xy_min(coord, 0, 0, 0)[k][1];
			shifted_coord[k][l] = coord[k][l] - x_min;
			l++;
			shifted_coord[k][l] = coord[k][l] - y_min;
			l++;
		}
		shifted_coord[k][l] = c++;
		k++;
	}
	shifted_coord[k] = NULL;
	return(shifted_coord);
}
*/
/*
** Function that counts the number of tetrominoes that are stored
** in a 2D-array.
*/
/*
int tetro_count(char **coordinates)
{
	int i; 

	i = 0;
	if(coordinates[i])
		while(coordinates[i] != NULL)
			i++;
	return(i);
}
*/

/*
** Function that takes the board size and generates a grid.
*/
/*
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
*/
/*
** Function coord_to_alpha takes coordinates that are shifted to the top left,
** and an empty grid. Then the function places alphabets onto the empty_grid
** at the shifted_coordinates location.
*/

//char **alpha_on_grid(int *new_shifted_coord, char **empty_grid)
/*
char **alpha_on_grid(int *shifted_coord, char **empty_grid)
{
	int i;
	int j;
	char c;

	i = 0;
	j = 0;
	c = 'A';

	while(i <= 7)
	{
		empty_grid[shifted_coord[i+1]][shifted_coord[i]] = shifted_coord[8];
		i = i + 2;
	}
	return(empty_grid);
}
*/
/*
** Function that prints the alphabets placed onto the grid.
*/
/*
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
*/
/*
** Function that will shift the tetromino by x and y. Adding 1 to x will move
** the tetromino to the right by 1 place. And adding 1 to y will move the
** the tetromino down by 1 place.
** Tetrominoes will be shifted when the pieces collide with each other,
** or go over board.
*/
/*
int			*shift_tetro(int *shifted_coord, int x, int y)
{
	int i;
	
	i = 0;
	while(i <= 7)
	{
		shifted_coord[i] = shifted_coord[i] + x;
		i++;
		shifted_coord[i] = shifted_coord[i] + y;
		i++;
	}
	return(shifted_coord);
}
*/
/*
** Functions that detect collision with the board size first and then pieces.
** Pieces cannot land on top of each other and the pieces cannot be placed
** outside the board/grid.
** Functions return 0 if there's no collision, or 1 if it detects collision.
** Function 1 - Collision with the pieces.
** Function 2 - Collision with the board.
*/
/*
int collision(char **empty_grid, int *shifted_coord, int board_size)
{
	int max;
	int i;

	max = 0;
	i = 0;

	while(i <= 7)
	{
		(shifted_coord[i] >= max) && (max =shifted_coord[i]);
		i++;
	}
	if (max >= board_size)
		return (1);
	i = 0;
	while(i <= 7)
	{
		if(empty_grid[shifted_coord[i+1]][shifted_coord[i]] != '.')
			return(1);
		i = i+2;
	}
	return(0);
}
*/
/*
** clear_tetro function will clear the tetromino piece if it was not placed
** properly, if it landed onto the existing piece or it was placed
** outside the board. 
*/
/*
void remove_tetro(char **empty_grid, int *shifted_coord)
{
	int i;
	i = 0;

	while(i <= 7)
	{
		empty_grid[shifted_coord[i+1]][shifted_coord[i]] = '.';
		i = i + 2;
	}
}
*/
/*
** A function that duplicates coordinates before starting backtracking
*/
/*
int		duplicate_coord(int *dest, int *shifted_coord)
{
	int i;
	int *new_dest;

	i = 0;
	new_dest = dest;
	while(i <= 8)
	{
		new_dest[i] = shifted_coord[i];
		i++;
	}
	return(1);
}
*/
