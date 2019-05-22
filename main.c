/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:42:03 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/22 12:11:33 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr(USAGE);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit();
	solve_driver1(fd);
//	doub_char = (char **)malloc(sizeof(char *) * (1));
//	doub_char = ft_tetrominoes(fd);
//	fd = dots_and_hash(doub_char);
//	fd = hash_touch(doub_char);//, 0, 0, 0);
//	fd = 1;	
//	printf("%d\n", fd);

	while(1);
	close(fd);
	return (0);
}
