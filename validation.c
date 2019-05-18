/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:21:30 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/17 19:49:29 by mbutt            ###   ########.fr       */
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
	characters[i] = NULL;
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
	while(characters[i])
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
	return(i);
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
** Tetrominoes will be shifted when the pieces collide with each other,
** or go over board.
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
** properly, if it landed onto the existing piece or it was placed outside the board. 
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
** A function that duplicates coordinates before starting backtracking
*/
int		duplicate_coordinates(int *dest, int *shifted_coordinates)
{
	int i;
	int *new_dest;

	i = 0;
	new_dest = dest;
	while(i <= 8)
	{
		new_dest[i] = shifted_coordinates[i];
		i++;
	}
	return(1);
}

/*
** Functions and algorithms that solves the tetromino and places
** tetrominoes in the smallest sqaure possible.
** This is where a lot of the previously created functions will be used.
** --------------------------- Backtracking-----------------------------
*/
//int place_next_piece(int *shifted_coordinates, char **empty_grid, int board_size, int i)
/*
int place_next_piece(int *shifted_coordinates, char ** empty_grid, int board_size)
{
	static int index;
	index = 0;

//	if(shifted_coordinates[index] == NULL)
//		return(0);
	printf("\nSolving tetro\n");
	if(!*shifted_coordinates)	
		return(EXIT_SUCCESS);
//	while(collision(empty_grid, shifted_coordinates, board_size) == 0)
	while(collision(empty_grid, shifted_coordinates, board_size) == EXIT_SUCCESS)
	{
		alpha_on_grid(shifted_coordinates, empty_grid);
		ft_print(empty_grid);
//		if(place_next_piece(shifted_coordinates,empty_grid, board_size, i+1) == 0)
//			return(0);
//		if(place_next_piece(shifted_coordinates, empty_grid, board_size, i+1) == EXIT_SUCCESS)
//			return(EXIT_SUCCESS);
		if(place_next_piece(&shifted_coordinates[index+1], empty_grid, board_size) == EXIT_SUCCESS)
			return(EXIT_SUCCESS);
		clear_tetro(empty_grid, shifted_coordinates);
	}
	return(1);
}


//int fill_board(int *shifted_coordinates, char **empty_grid, int board_size, int i)
int fill_board(int *shifted_coordinates, char **empty_grid, int board_size)
{
//	while(place_next_piece(shifted_coordinates, empty_grid, board_size, i))
//	while(place_next_piece(shifted_coordinates, empty_grid, board_size))
	while(collision(empty_grid, shifted_coordinates, board_size) != EXIT_SUCCESS)
	{
//		if(place_next_piece(shifted_coordinates, empty_grid, board_size, i) == 0)
//			break;
//		if(place_next_piece(shifted_coordinates, empty_grid, board_size, i) == EXIT_SUCCESS)
//			break;
		if(place_next_piece(shifted_coordinates, empty_grid, board_size) == EXIT_SUCCESS)
			break;
		board_size++;
	}
	return(*shifted_coordinates);	
//	return(board_size);
}
*/
/*
char **solve_tetro(char **empty_grid, int **shifted_coordinates, int board_size)
{
	int x;
	int y;
	int i;
	int x2;
	int y2;
	int total_attempts;
	int *dest;
	
	i = 0;
	x2 = 0;
	y2 = 0;

	if(!x)
		x = 0;
	if(!y)
		y = 0;

	if(collision(empty_grid, shifted_coordinates[i+1], board_size) == 1)
	{
		while(x <= board_size)
		{
			duplicate_coordinates(dest, *shifted_coordinates);

		//	shift_tetro(shifted_coordinates[i+1], x, y);
			shift_tetro(shifted_coordinates[i+1], x ,y);
			total_attempts++;
			x++;
			solve_tetro(empty_grid, &shifted_coordinates[i+1], board_size);
		}
		if(x == board_size && y == board_size)
		{
			clear_tetro(empty_grid, *shifted_coordinates);
			x2++;
			if(x2 > board_size)
			{
				x2 = 0;
				y2++;
			}
			x = 0;
			y = 0;
//			if(x2 == board_size && y2 == board_size)
//			{
//			}
			shift_tetro(*shifted_coordinates, x2, y2);
		}
		if(x > board_size)
		{
			x = 0;
			total_attempts++;
			y++;
		}
	}
	if((collision(empty_grid, shifted_coordinates[i], board_size) == 0) && i <= 3)
	{
		alpha_on_grid(shifted_coordinates[i], empty_grid);
		i++;
		printf("\nCounts1\n");
		solve_tetro(empty_grid, shifted_coordinates, board_size);
	}
	ft_print(empty_grid);
	return(0);
//		while(x > board_size)
//		{
//			shift_tetro(shifted_coordinates, x, y);

//		}
//	}
}
*/
//int help_solve(char **empty_grid, int *shifted_coordinates, int **shifted_coordinates_2, int board_size)
/*
int help_solve(char **empty_grid, int *shifted_coordinates, t_tetro *stack, int board_size)
{
	printf("\nEnters help_solve\n");
//	static int i;
//	i = 0;
	if(collision(empty_grid, shifted_coordinates, board_size))
	{
		alpha_on_grid(shifted_coordinates, empty_grid);
//		printf("%s\n", alpha_on_grid(shifted_coordinates, empty_grid)[0]);
//		if (solve_tet(empty_grid, shifted_coordinates_2, board_size)) // *shifted_coordinates
		if (solve_tet(empty_grid, stack->next, board_size))
		{
//			i++;
			free(shifted_coordinates);
			return(1);
		}
//		printf("%s\n", alpha_on_grid(shifted_coordinates, empty_grid)[0]);
//		i = i-1;
		clear_tetro(empty_grid, shifted_coordinates);
	}
	return(0);
}
*/
/*
//int solve_tet(char **empty_grid, int **shifted_coordinates_2, int board_size, int *i)
int solve_tet(char **empty_grid, t_tetro *stack, int board_size)
{
	int *temp_coord;
	int x;
	int y;

	x = 0;
	y = 0;
//	duplicate_coordinates(temo_coord, shifted_coordinates_2[i]);
	temp_coord = (int *)malloc(sizeof(int) * 9); // malloc 9 for alpha_on_grid
	if(!stack)
	{
		free(temp_coord);
		return(1);
	}
	while(y < board_size)
	{
		while(x < board_size)
		{
//			duplicate_coordinates(temp_coord, shifted_coordinates_2[i]);
			duplicate_coordinates(temp_coord, stack->struct_tetro);
			shift_tetro(temp_coord, x, y);
//			if (help_solve(empty_grid, temp_coord, &shifted_coordinates_2, board_size))
			if (help_solve(empty_grid, temp_coord, stack, board_size))
				return(1);
			x++;
		}
		x = 0;
		y++;
	}
	free(temp_coord);
	return(0);

}
*/
/*
int solve_tet_one(char **empty_grid, int *shifted_coordinates, int **shifted_coordinates_2, int board_size)
{
	int *temp;
	int i;
	int x;
	int y;

	temp = (int *)malloc(sizeof(int) * 10);
	x = 0;
	y = 0;
	i = 0;

	if(collision(empty_grid, shifted_coordinates,  board_size))
	{
		alpha_on_grid(shifted_coordinates, empty_grid);
		if(solve_tet_one(empty_grid, shifted_coordinates, &shifted_coordinates_2[i++], board_size))
			return(1);
		clear_tetro(empty_grid, shifted_coordinates);
	}
	while(y < board_size)
	{
		while(x < board_size)
		{
			duplicate_coordinates(temp, *shifted_coordinates_2);
			shift_tetro(temp, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return(0);
}
*/
/*
int solve_driver(fd)
{
//	int 	temp;
//	int 	tetro_count;
	char 	**characters;
	int 	**shifted_coordinates;
	t_tetro *temp;
	t_tetro *stack;
	int 	board_size;
	char	**empty_grid;

	characters = ft_tetrominoes(fd);
//	temp = store_tet(fd, NULL); //dont need this
//	board_size = start_size(temp); // missing function
	board_size = 4;
//	shifted_coordinates = (shift_xy_coordinates(shifted_coordinates, 3, 3, 0));
//	stack = *shift_xy_coordinates(stack->struct_tetro, 3, 3, 0);
	stack = coord_to_struct(shifted_coordinates, tetro_count(characters));
	empty_grid = ft_grid(board_size);
//	while(!solve_tet(empty_grid, shifted_coordinates, board_size))
	while(!solve_tet(empty_grid, stack, board_size))
	{
//		free_grid(empty_grid, board_size); // dont have this function
		board_size++;
		empty_grid = ft_grid(board_size);
	}
	ft_print(empty_grid);
//	stck_free_coord(stack); // dont have this function
	return(1);
}
*/

/*
int solve_driver_one(fd)
{
//	t_tetro		*tmp;
//	t_tetro		*stack;
	int			*shifted_coordinates;
	int			**shifted_coordinates_2;
	int			board_size;
	char		**empty_grid;
	char 		**characters;
	int			**coordinates;

	characters = ft_tetrominoes(fd);
	board_size = 4;
	coordinates= xy_coordinates(characters, 0, 0, 0);
	shifted_coordinates_2 = shift_xy_coordinates(coordinates, 3, 3, 0);
	empty_grid = ft_grid(board_size);

	while(!solve_tet_one(empty_grid, shifted_coordinates, shifted_coordinates_2, board_size))
	{
		board_size++;
		ft_grid(board_size);
	}
	ft_print(empty_grid);
	return(1);

}
*/
int help_solve(char **empty_grid, int *shifted_coordinates, t_tetro *stack, int board_size)
{
	printf("\n1help_solve\n");
//	if(!collision(empty_grid, shifted_coordinates, board_size))
	if(collision(empty_grid, shifted_coordinates, board_size) == 0)
	{
		printf("\ninside if\n");
		alpha_on_grid(shifted_coordinates, empty_grid);
		printf("\nafter alpha\n");
		if (solve_tet(empty_grid, stack->next, board_size))
		{
			printf("\nin if and if\n");
			free(shifted_coordinates);
			return(1);
		}
		clear_tetro(empty_grid, shifted_coordinates);
	}
	return(0);
}

int solve_tet(char **empty_grid, t_tetro *stack, int board_size)
{
//	printf("\nprinting solve_tet\n");
	int *shifted_coordinates;
	int x;
	int y;

	y = -1;

	shifted_coordinates = (int *)malloc(sizeof(int) * 9);
	printf("\nsolve_tet\n");
	if(!stack)
	{
		free(shifted_coordinates);
		return(1);
	}
	while(++y < board_size)
	{
		x = -1;
		while(++x < board_size)
		{
			duplicate_coordinates(shifted_coordinates, stack->struct_tetro);
			shift_tetro(shifted_coordinates, x, y);
			printf("\nabc\n");
			if (help_solve(empty_grid, shifted_coordinates, stack, board_size))
				return(1);
		}
	}
	free(shifted_coordinates);
	return(0);
}

int solve_driver(int fd)
{
	printf("\nprintg solve_driver1\n");
	t_tetro	*tmp;
	t_tetro	*stack;
	char	**characters;
	int		tet_count;
	int 	**coordinates;
	int		**shifted_coordinates;
	int 	board_size;
	char	**empty_grid;

	characters = ft_tetrominoes(fd);
	printf("\nprinting solve_driver2\n");
	tet_count  = tetro_count(characters);
	printf("\ntetro_count:|%d|\n", tet_count);	
	printf("\n11\n");
	coordinates = xy_coordinates(characters, 0, 0, 0);
	printf("\n2\n");
	shifted_coordinates = shift_xy_coordinates(coordinates, 3, 3, 0);
	printf("\n3\n");
	stack = coord_to_struct(shifted_coordinates, tet_count);
	printf("\ntet_count|%d|\n", tet_count);
	printf("\nprinting solve_driver3\n");
	empty_grid = ft_grid(board_size = 4);
	while(!solve_tet(empty_grid, stack, board_size))
	{
		//free_grid(empty_grid, board_size); // dont have function
		board_size++;
		empty_grid = ft_grid(board_size);
	}
	ft_print(empty_grid); // dont have function
//	stck_free_coord(stack); // dont have function
	return(1);

}
//-------------------------------MAIN-------------------------

int main (int argc, char **argv)
{
	int fd;
	fd = 0;
	printf("---Enters main---\n");
	if(argc != 2)
	{
		ft_putstr(USAGE);
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);

	if(fd == -1)
		ft_exit();
//	else if(fd > 0)
//	{
//		fd = open(argv[1], O_RDONLY);
		solve_driver(fd);
//	}
	close(fd);
}

