/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:46:13 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/27 17:03:13 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

char **ft_grid(int width)
{
	int new_width;
	int height;
	int i;
	int j;
	char **empty_grid;

	new_width = width;
	i = 0;
	j = 0;
	height = width;
	
	empty_grid = (char **)malloc(sizeof(char *) * (width));

	while(width)
	{
		empty_grid[i] = (char *)malloc(sizeof(char) * (width + 1));
		i++;
		width--;
	}
	width = i;
	i = 0;

	while(height)
	{
		while(new_width)
		{
			empty_grid[i][j] = '.';
			j++;
			new_width--;
		}
		empty_grid[i][j] = '\n';
		j = 0;
		i++;
		new_width = width;
		height--;
	}
	return(empty_grid);
}

int main (void)
{
	char **empty_grid;
	int num;
	int i;

	num = 13;
	i = 0;
	empty_grid = ft_grid(num);
	
//	ft_putstr(empty_grid[0]);
//	ft_putstr(empty_grid[1]);
//	ft_putstr(empty_grid[2]);
//	ft_putstr(empty_grid[3]);

	while(i < num)
	{
//		printf("%s", empty_grid[i]);
		ft_putstr(empty_grid[i]);
		i++;
	}
}
