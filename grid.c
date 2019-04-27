/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:46:13 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/27 15:18:57 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

char **ft_grid(int width)
{
	int default_width;
	int height;
	int i;
	int j;
	char **empty_grid;
//	int default_width;
//	int height;

	default_width = width;
	i = 0;
	j = 0;
	
	empty_grid = (char **)malloc(sizeof(char *) * (default_width + 1));

	while(width)
	{
		empty_grid[i] = (char *)malloc(sizeof(char) *(default_width + 1));
		i++;
		width--;
	}
	width = i;
	i = 0;

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
		width = default_width;
		height--;
	}
	return(empty_grid);
}

int main (void)
{
	char **empty_grid;
	empty_grid = ft_grid(4);
	//ft_grid(4);
	//printf("%s", *ft_grid(4));
	printf("%s", empty_grid[0]);
	printf("%s", empty_grid[1]);
	printf("%s", empty_grid[2]);
	printf("%s", empty_grid[3]);

}
