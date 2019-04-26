/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:39:58 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/25 19:46:29 by mbutt            ###   ########.fr       */
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
	int buff_size = 1;
//	char *one_line;
	char placeholder[buff_size];
	//char placeholder[buff_size + 1];
	fd1 = open("tests/corrects/valid_20", O_RDONLY);
	//bytes_read = read(fd1, placeholder, buff_size);
	while((bytes_read = read(fd1, placeholder, buff_size) > 0))
	{
		placeholder[buff_size] = '\0';
		printf("%s", placeholder);
	}

	return(0);

}
