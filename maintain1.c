/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintain1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:06:59 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/18 19:16:53 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** To print the Error message and exit if the tetrominoes are not valid at any
** stage.
*/

void	ft_exit(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

/*
** Function that counts the number of tetrominoes that are stored
** in a 2D-array.
*/

int		tetro_count(char **coordinates)
{
	int i;

	i = 0;
	if (coordinates[i])
		while (coordinates[i] != NULL)
			i++;
	return (i);
}

/*
** Function that takes the board size and generates a grid.
*/

char	**ft_grid(int width)
{
	int		height;
	int		i;
	int		j;
	char	**empty_grid;

	i = 0;
	j = 0;
	height = width;
	empty_grid = (char **)malloc(sizeof(char *) * (width + 1));
	while (width != i)
		empty_grid[i++] = (char *)malloc(sizeof(char) * (width + 1));
	i = 0;
	while (height--)
	{
		while (width != j)
			empty_grid[i][j++] = '.';
		empty_grid[i][j] = '\0';
		j = 0;
		i++;
	}
	empty_grid[i] = NULL;
	return (empty_grid);
}

/*
** A function that duplicates coordinates before starting backtracking
*/

int		duplicate_coord(int *dest, int *shifted_coord)
{
	int i;
	int *new_dest;

	i = 0;
	new_dest = dest;
	while (i <= 8)
	{
		new_dest[i] = shifted_coord[i];
		i++;
	}
	return (1);
}
