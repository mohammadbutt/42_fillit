/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:46:13 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/07 13:44:35 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

char **ft_grid(int width)
{
//	int default_width;
	int height;
	int i;
	int j;
	char **empty_grid;

//	default_width = width;
	i = 0;
	j = 0;
	height = width;	
	empty_grid = (char **)malloc(sizeof(char *) * (width + 1));
//	while(width--)
	while(width != i)
	{
		empty_grid[i++] = (char *)malloc(sizeof(char) * (width + 1));
	}
//	width = i;
	i = 0;

	while(height--)
	{
		while(width != j)
		{
			empty_grid[i][j++] = '.';
//			j++;
//			width--;
		}
//		empty_grid[i][j] = '\n';
		empty_grid[i][j] = '\0';
		j = 0;
		i++;
//		width = default_width;
//		height--;
	}
	empty_grid[i] = NULL;
//	height = width;
	return(empty_grid);
}

int main (void)
{
	char **empty_grid;
	int num;
	int i;

	num = 2;
	i = 0;
	empty_grid = ft_grid(num);
	
//	ft_putstr(empty_grid[0]);
//	ft_putstr(empty_grid[1]);
//	ft_putstr(empty_grid[2]);
//	ft_putstr(empty_grid[3]);
	printf("grid of %d by %d\n", num, num);
	while(i < num)
	{
//		printf("%s", empty_grid[i]);
		ft_putstr(empty_grid[i]);
		ft_putstr("\n");
//		free(empty_grid[i]);
		i++;
	}
}
