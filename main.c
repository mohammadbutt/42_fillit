/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:42:03 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/19 15:54:43 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char const *string)
{
	int i;

	i = 0;
	if (string[i])
		while (string[i])
			write(1, &string[i++], 1);
}

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
	close(fd);
	return (0);
}
