/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:39:58 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/26 15:49:37 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

int main (void)
{
/*
	FILE *fd1;
	char *line = NULL;
	size_t buff_size = 0;
	int ret1;


	fd1 = fopen("tests/corrects/valid_00", "r");
	while((ret1 = getline(&line, &buff_size, fd1)))
	{
		if (ret1 > 0)
		{
			printf("%s", line);
		}
		else
			break;
	}
*/
	int fd1;
//	int ret1;
	int bytes_read;
//	int buff_size = 1;
	int buff_size = 20;
//	char *one_line;
	char placeholder[buff_size];
	char user_piece[20];
	int i = 0;
	//char placeholder[buff_size + 1];
//	fd1 = open("tests/corrects/valid_20", O_RDONLY);
	fd1 = open("valid_pieces/valid_01", O_RDONLY);	
//bytes_read = read(fd1, placeholder, buff_size);
/*
	while((bytes_read = read(fd1, placeholder, buff_size) > 0))
	{
		placeholder[buff_size] = '\0';
		printf("%s", placeholder);
	}
*/
	while((bytes_read = read(fd1, placeholder, buff_size) > 0))
	{
		placeholder[buff_size] = '\0';
		ft_strcpy(user_piece, placeholder);
//		user_piece[i] = *placeholder;
//
		
		i++;
//		printf("")
	}
	printf("%s\n\n", placeholder);
	
	if(ft_strcmp(p01, user_piece) == 0)
	{
		printf("%s", user_piece);
		printf("\nuser piece matches");
	}
	else
	{
		printf("\nError, piece does not match");
	}

	return(0);

}
