/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:23:55 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/26 20:03:41 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

/*
// single pointer Linear array 
int main (void)
{
	int height;
	int width;
	int i;

	height = 7;
	width = 7;
	i 	  = 0;

	char empty_grid[height*width];

//	while(height)
//	{
//		while (width)
//		{
//			printf(".");
//			width--;
//		}
//		printf("\n");
//		width = 7;
//		height--;
//	}

	while(height)
	{
		while(width)
		{
			empty_grid[i] = '.';
			i++;
			width--;
		}
		empty_grid[i] = '\n';
		i++;
		width = 7;
		height--;
	}
	empty_grid[10] = 'd';
	printf("%s", empty_grid);
	return(0);
}
*/
// Double pointer 2 dimensional array to take in x and y coordinates.
int main (void)
{
	int height;
	int width;
	int i;
	int j;

	height = 4;
	width = 4;
	i = 0;
	j = 0;

	char *empty_grid[height*width];
/*
	while(height)
	{
		while(width)
		{
			empty_grid[i] = '.';
			i++;
			width--;
		}
		empty_grid[i] = '\n';
		i++;
		width = 4;
		height--;
	}
*/

	while(height)
	{
		while(width)
		{
			empty_grid[i][j] = '.';
			j++;
			width--;
		}
		empty_grid[i][j] = '\n';
		j = 0;
		i++;
		width = 4;
		height--;
	}
	printf("this is i:|%d|\n", i);
	printf("this is j:|%d|\n", j);
	printf("%s", *empty_grid);
	return(0);
}
