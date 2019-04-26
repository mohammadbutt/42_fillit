/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:07:29 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/25 20:28:48 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main (void)
{
	char *piece01;
	char *piece02;
	char *piece03;
	char *piece04;
	char *piece05;

	piece01 = (char *) malloc(20);
	piece02 = (char *) malloc(20);
	piece03 = (char *) malloc(20);
	piece04 = (char *) malloc(20);
	piece05 = (char *) malloc(20);

	piece01 = "###.\n.#..\n....\n....\n";
	piece02 = "#...\n#...\n#...\n#...\n";
	piece03 = "##..\n#...\n#...\n....\n";
	piece04 = "#...\n##..\n#...\n....\n";
	piece05 = "#...\n#...\n##..\n....\n";
/*	
	printf("%s\n", piece01);
	printf("%s\n", piece02);
	printf("%s\n", piece03);
	printf("%s\n", piece04);
	printf("%s\n", piece05);
*/
	return(0);
}
