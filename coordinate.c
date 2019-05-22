/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:02:57 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/22 13:19:56 by mbutt            ###   ########.fr       */
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
	coordinates = (int **)malloc(sizeof(int *) * (26));
	while (characters[i])
	{
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
** Calculating x_min and y_min by creating 2 seperate function,
** so there's no need to free it later.
*/

int		ft_x_min(int *coord)
{
	int l;
	int x_min;

	l = 0;
	x_min = 3;
	while (l <= 7)
	{
		if (coord[l] <= x_min)
			x_min = coord[l];
		l = l + 2;
	}
	return (x_min);
}

int		ft_y_min(int *coord)
{
	int l;
	int y_min;

	l = 1;
	y_min = 3;
	while (l <= 7)
	{
		if (coord[l] <= y_min)
			y_min = coord[l];
		l = l + 2;
	}
	return (y_min);
}

/*
** Coordinates are shifted to top left location. This is done by subtracting
** x_min and y_min from the original coordinates.
*/

int		**shift_xy_coord(int **coord, int x_min, int y_min, int k)
{
	int		**shifted_coord;
	char	c;
	int		l;

	c = 'A';
	k = 0;
	shifted_coord = (int **)malloc(sizeof(int *) * (27));
	while (coord[k] != NULL)
	{
		ft_variable_reset(&x_min, &y_min, &l);
		shifted_coord[k] = (int *)malloc(sizeof(int) * (9));
		while (l <= 7)
		{
			x_min = ft_x_min(coord[k]);
			y_min = ft_y_min(coord[k]);
			shifted_coord[k][l] = coord[k][l] - x_min;
			l++;
			shifted_coord[k][l] = coord[k][l] - y_min;
			l++;
		}
		shifted_coord[k][l] = c++;
		k++;
	}
	shifted_coord[k] = NULL;
	return (shifted_coord);
}
