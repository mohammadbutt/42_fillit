/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:37:00 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/22 15:57:32 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Takes a 2D-array of char and frees each dependent child and then frees the
** parent.
*/

void	free_2d_char(char **empty_grid)
{
	int i;

	i = 0;
	if (empty_grid)
		while (empty_grid[i])
		{
			free(empty_grid[i]);
			i++;
		}
	free(empty_grid);
}

/*
** Takes a 2D-array of int and frees each dependent child and then frees the
** parent.
*/

void	free_2d_int(int **coordinates)
{
	int i;

	i = 0;
	if (coordinates)
		while (coordinates[i])
		{
			free(coordinates[i]);
			i++;
		}
	free(coordinates);
}
