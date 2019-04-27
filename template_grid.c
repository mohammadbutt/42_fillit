/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:23:55 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/27 14:45:48 by mbutt            ###   ########.fr       */
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
	char dot;

	height = 4;
	width = 4;
	i = 0;
	j = 0;
//	dot = 0;
	char empty_grid[height][width];
//	char **empty_grid;
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
// Allocate memory to have 4 rows.	
//	empty_grid = (char **)malloc(sizeof(char *)*(4));

//Allocate memory to have 4 characters for each row
//	empty_grid[0] = (char *)malloc(sizeof(char)*(width + 1));
//	empty_grid[1] = (char *)malloc(sizeof(char)*(width + 1));
//	empty_grid[2] = (char *)malloc(sizeof(char)*(width + 1));
//	empty_grid[3] = (char *)malloc(sizeof(char)*(width + 1));

	while(height)
	{
		while(width)
		{
			empty_grid[i][j] = '.';
//			empty_grid[i][j] = dot;
//			dot++;
			j++;
			width--;
//			printf("%d\n", j);
		}
//		ft_strcpy(empty_grid[j], "\n");
		empty_grid[i][j] = '\n';
		j = 0;
		i++;
		width = 4;
		height--;
//		printf("this is i:|%d|\n", i);
	}
//	printf("outside -i:|%d|\n", i);
//	printf("outside -j:|%d|\n", j);
	printf("Elements we have access to in 0:\n");
	printf("%c", empty_grid[0][0]);
	printf("%c", empty_grid[0][1]);
	printf("%c", empty_grid[0][2]);
	printf("%c", empty_grid[0][3]);
	printf("|%c", empty_grid[0][4]);
	printf("%c", empty_grid[0][5]);
	printf("%c", empty_grid[0][6]);
	printf("%c", empty_grid[0][7]);
	printf("%c", empty_grid[0][8]);
	printf("%c", empty_grid[0][9]);
	printf("%c", empty_grid[0][10]);
	printf("%c", empty_grid[0][11]);
	printf("%c", empty_grid[0][12]);
	printf("%c", empty_grid[0][13]);
	printf("%c", empty_grid[0][14]);
	printf("%c", empty_grid[0][15]);
	printf("%c\n", empty_grid[0][16]);
	printf("%c",   empty_grid[0][17]);
	printf("%c\n\n\n", empty_grid[0][18]);

	printf("Printing grid\n");
	printf("%c", empty_grid[0][0]);
	printf("%c", empty_grid[0][1]);
	printf("%c", empty_grid[0][2]);
	printf("%c", empty_grid[0][3]);
	printf("%c\n", empty_grid[0][4]);

	printf("%c", empty_grid[1][0]);
	printf("%c", empty_grid[1][1]);
	printf("%c", empty_grid[1][2]);
	printf("%c\n", empty_grid[1][3]);

	printf("%c", empty_grid[2][0]);
	printf("%c", empty_grid[2][1]);
	printf("%c", empty_grid[2][2]);
	printf("%c\n", empty_grid[2][3]);

	printf("%c", empty_grid[3][0]);
	printf("%c", empty_grid[3][1]);
	printf("%c", empty_grid[3][2]);
	printf("%c\n\n", empty_grid[3][3]);

	printf("----------Replacing . with numbers----------\n");


	empty_grid[0][0] = 'a';
	empty_grid[0][1] = 'b';
	empty_grid[0][2] = 'c';
	empty_grid[0][3] = 'd';
//	empty_grid[0][4] = 'e';
	empty_grid[0][5] = 'f';
	empty_grid[0][6] = 'g';
	empty_grid[0][7] = 'h';
	empty_grid[0][8] = 'i';
	empty_grid[0][9] = 'j';
	empty_grid[0][10] = 'k';
	empty_grid[0][11] = 'l';
	empty_grid[0][12] = 'm';
	empty_grid[0][13] = 'n';
	empty_grid[0][14] = 'o';
	empty_grid[0][15] = 'p';
//	empty_grid[0][16] = 'q';
//	empty_grid[0][17] = 'q';
//	empty_grid[0][18] = 'r';
//	empty_grid[0][19] = 's';
//	empty_grid[0][20] = 't';

	printf("%c", empty_grid[0][0]);
	printf("%c", empty_grid[0][1]);
	printf("%c", empty_grid[0][2]);
	printf("%c", empty_grid[0][3]);
	printf("%c", empty_grid[0][4]);
	printf("%c", empty_grid[0][5]);
	printf("%c", empty_grid[0][6]);
	printf("%c", empty_grid[0][7]);
	printf("%c", empty_grid[0][8]);
	printf("%c", empty_grid[0][9]);
	printf("%c", empty_grid[0][10]);
	printf("%c", empty_grid[0][11]);
	printf("%c", empty_grid[0][12]);
	printf("%c", empty_grid[0][13]);
	printf("%c", empty_grid[0][14]);
	printf("%c", empty_grid[0][15]);
	printf("%c\n", empty_grid[0][16]);
	printf("?%c\n", empty_grid[0][17]);
	printf("?%c\n", empty_grid[0][18]);
	printf("?%c\n", empty_grid[0][19]);
	printf("?%c\n\n", empty_grid[0][20]);


	printf("printing grid again\n");
	printf("%c", empty_grid[0][0]);
	printf("%c", empty_grid[0][1]);
	printf("%c", empty_grid[0][2]);
	printf("%c", empty_grid[0][3]);
	printf("%c", empty_grid[0][4]);



	printf("%c", empty_grid[1][0]);
	printf("%c", empty_grid[1][1]);
	printf("%c", empty_grid[1][2]);
	printf("%c", empty_grid[1][3]);
	printf("%c", empty_grid[1][4]);

	printf("%c", empty_grid[2][0]);
	printf("%c", empty_grid[2][1]);
	printf("%c", empty_grid[2][2]);
	printf("%c", empty_grid[2][3]);
	printf("%c", empty_grid[2][4]);

	printf("%c", empty_grid[3][0]);
	printf("%c", empty_grid[3][1]);
	printf("%c", empty_grid[3][2]);
	printf("%c", empty_grid[3][3]);
	printf("%c", empty_grid[3][4]);

/*
	printf("Elements we have access to in 0:\n");	
	printf("%c", empty_grid[0][0]);
	printf("%c", empty_grid[0][1]);
	printf("%c", empty_grid[0][2]);
	printf("%c", empty_grid[0][3]);
	printf("%c", empty_grid[0][4]);
	printf("%c", empty_grid[0][5]);
	printf("%c", empty_grid[0][6]);
	printf("%c", empty_grid[0][7]);
	printf("%c", empty_grid[0][8]);
	printf("%c", empty_grid[0][9]);
	printf("%c", empty_grid[0][10]);
	printf("%c", empty_grid[0][11]);
	printf("%c", empty_grid[0][12]);
	printf("%c", empty_grid[0][13]);
	printf("%c", empty_grid[0][14]);
	printf("%c", empty_grid[0][15]);
	printf("%c\n", empty_grid[0][16]);
	printf("%c",   empty_grid[0][17]);
	printf("%c\n", empty_grid[0][18]);
*/

	return(0);
}
