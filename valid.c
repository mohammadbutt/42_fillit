/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:38:32 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/21 15:26:23 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** First step in the project. ft_tetrominoes stores the pieces given by
** the user in a double pointer array. But it also checks if the first,
** second, third, and fourth lines end with a new line.
** variable sd is just a temporary placeholder.
** If values are directly stored, using read, into characters[i] then the
** program will leak. Hence, values are first stored into a temporary
** placeholder called sd, and then stored to characters.
*/

char	**ft_tetrominoes(int fd, int bytes_read, int temp_bytes_read, int i)
{
	char	**characters;
	char	sd[21 + 1];

	initialize_with_zero(&bytes_read, &temp_bytes_read, &i);
	characters = (char **)malloc(sizeof(char *) * (27));
	while ((bytes_read = read(fd, sd, 21)) >= 20)
	{
		if (sd[4] != '\n' || sd[9] != '\n' || sd[14] != '\n' || sd[19] != '\n')
			ft_exit();
		else
		{
			temp_bytes_read = bytes_read;
			sd[20] = '\0';
			characters[i] = (char *)malloc(sizeof(char) * (22));
			ft_strcpy(characters[i], sd);
			ft_bzero(sd);
			i++;
		}
	}
	characters[i] = NULL;
	if (temp_bytes_read != 20)
		ft_exit();
	return (characters);
}

/*
** dots_and_hash returns an integer. If there are not 12 dots or 4 hastags,
** then the program will print "Error" and exit out of the program.
** If there are 12 dots and 4 hashtags then the program will return 1
** which means the program can now be validated for the next phase to determine
** if the pieces entered by the user are actually tetrominoes or not.
*/

int		dots_and_hash(char **characters)
{
	int	i;
	int	j;
	int	dots;
	int	hashtags;

	i = 0;
	j = 0;
	while (characters[i])
	{
		dots = 0;
		hashtags = 0;
		while (characters[i][j] != '\0')
		{
			(characters[i][j] == '.') && (dots++);
			(characters[i][j] == '#') && (hashtags++);
			j++;
		}
		if (dots != 12 || hashtags != 4)
			ft_exit();
		i++;
		j = 0;
	}
	return (1);
}

/*
** function initializes values to 0.
*/

int		initialize_with_zero(int *i, int *j, int *hash)
{
	*i = 0;
	*j = 0;
	*hash = 0;
	return (0);
}

/*
** Counts how many time a hashtag touches another. The count should be
** equal to 6 or 8.
*/
/*
** i, j, and hash are placed within the function to save lines inside the
** function.
** It is important to set i, j, and hash at 0 in the main or wherever
** this function gets called.
*/


int		hash_touch(char **characters, int i, int j, int hash)
{
	initialize_with_zero(&i, &j, &hash);
	while (characters[i])
	{
		while (j < 20)
		{
			if (characters[i][j] == '#')
			{
				(characters[i][j + 1] == '#') && hash++;
				(characters[i][j + 5] == '#') && hash++;
				(characters[i][j - 1] == '#') && hash++;
				(characters[i][j - 5] == '#') && hash++;
			}
			j++;
			if (j == 20 && (hash == 6 || hash == 8))
				break ;
			if (j == 20 && (hash != 6 || hash != 8))
				ft_exit();
		}
		i++;
		j = 0;
		hash = 0;
	}
	return (1);
}

/*
** Calls on to previous functions dots_and_hash and hash_touch
** to determine if a piece read is valid or not.
*/

int		is_it_valid(char **characters)
{
	dots_and_hash(characters);
	hash_touch(characters, 0, 0, 0);
//	printf("%s", characters[0]);

//	if(dots_and_hash(characters) != 1)
//		ft_exit();
//	if(hash_touch(characters, 0, 0, 0) != 1)
//		ft_exit();
//	free_grid(characters);
//	free(characters);
	return (1);
}

/*
** Above functions are done validating a tetromino. If a tetromino piece
** made it this far then the tetromino is valid.
*/
