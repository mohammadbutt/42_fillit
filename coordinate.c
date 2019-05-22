/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:02:57 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/21 20:26:07 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Tuning tetrominoes into coordinates.
** Index of a tetromino % 5 gives x.
** Same index of the tetromino / 5 gives y.
** We modulo and divide by 5 because each line has 5 elements from 0 to 19.
** For instance 15th place % 5 is 0, And 15th place / 5 is 3. This gives us
** x = 0 and y 3.
*/

int		initialize_xy_coord(int *i, int *j, int *k, int *l)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*l = 0;
	return (0);
}

int		**xy_coord(char **characters, int i, int j, int k)
{
	int	l;
	int	**coordinates;

	initialize_xy_coord(&i, &j, &k, &l);
//	coordinates = (int **)malloc(sizeof(int *) * (27));
	coordinates = (int **)malloc(sizeof(int *) * (26));
	while (characters[i])
	{
//		coordinates[k] = (int *)malloc(sizeof(int) * (9));
		coordinates[k] = (int *)malloc(sizeof(int) * (8));
		while (characters[i][j] != '\0')
		{
			if (characters[i][j] == '#')
			{
				coordinates[k][l++] = j % 5;
				coordinates[k][l++] = j / 5;
			}
			j++;
		}
		i++;
		j = 0;
		l = 0;
		k++;
	}
//	free_2d_char(characters); // Adding for leaks
	coordinates[k] = NULL;
	return (coordinates);
}

/*
** An auxiliary function that sets the variables to these values in
** xy_min and shift_xy_coord function
*/

int		ft_variable_reset(int *x_min, int *y_min, int *l)
{
	*x_min = 3;
	*y_min = 3;
	*l = 0;
	return (0);
}

/*
** Calculating x_min and y_min.
** This function takes in a 2D-array, k, l, and x. k, l, and x are set to 0,
** wherever the function gets called.
** This function stores x on 0th element and y on 1st element of an array.
*/

int		**xy_min(int **coord, int k, int l, int x)
{
	int **min;
	int y;

	y = 1;
	min = (int **)malloc(sizeof(int *) * (27));
	while (coord[k] != NULL)
	{
		min[k] = (int *)malloc(sizeof(int) * 2);
		ft_variable_reset(&min[k][x], &min[k][y], &l);
		while (l <= 7)
		{
			if (coord[k][l] <= min[k][x])
				min[k][x] = coord[k][l];
			l++;
			if (coord[k][l] <= min[k][y])
				min[k][y] = coord[k][l];
			l++;
		}
		k++;
	}
	return (min);
}

/*
** Coordinates are shifted to top left location. This is done by subtracting
** x_min and y_min from the original coordinates.
*/

//int		**shift_xy_coord(int **coord, int x_min, int y_min, int k)
int		**shift_xy_coord(int **coord, int **min, int x_min, int y_min)
{
	int		**shifted_coord;
	char	c;
	int		l;
	int		k;
	//	int		**min; // Adding this for leaks
	
	c = 'A';
	k = 0;
	shifted_coord = (int **)malloc(sizeof(int *) * (27));
	while (coord[k] != NULL)
	{
		ft_variable_reset(&x_min, &y_min, &l);
		shifted_coord[k] = (int *)malloc(sizeof(int) * (9));
		while (l <= 7)
		{
			min = xy_min(coord, 0, 0, 0);
			x_min = min[k][0];
			y_min = min[k][1];
//			x_min = xy_min(coord, 0, 0, 0)[k][0]; commenting for leaks. Original
//			y_min = xy_min(coord, 0, 0, 0)[k][1]; commenting for leaks. Original
			shifted_coord[k][l] = coord[k][l] - x_min;
			l++;
			shifted_coord[k][l] = coord[k][l] - y_min;
			l++;
		}
		shifted_coord[k][l] = c++;
		k++;
	}
//	free_2d_int(coord);
//	free_2d_int(min);
	shifted_coord[k] = NULL;
	return (shifted_coord);
}
