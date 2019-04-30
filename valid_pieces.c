/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:07:29 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/29 22:21:51 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
int main (void)
{
	char *p01;
	char *p02;
	char *p03;
	char *p04;
	char *p05;
	char *p06;
	char *p07;

	p01 = (char *)malloc(20);
	p02 = (char *)malloc(20);
	p03 = (char *)malloc(20);
	p04 = (char *)malloc(20);
	p05 = (char *)malloc(20);
	p06 = (char *)malloc(20);
	p07 = (char *)malloc(20);

	p01 = "###.\n.#..\n....\n....\n";
	p02 = "#...\n#...\n#...\n#...\n";
	p03 = "##..\n#...\n#...\n....\n";
	p04 = "#...\n##..\n#...\n....\n";
	p05 = "#...\n#...\n##..\n....\n";
	p06 = ".#..\n##..\n#...\n....\n";
	p07 = "##..\n##..\n....\n....\n";
	
//	printf("%s\n", p01);
//	printf("%s\n", p02);
//	printf("%s\n", p03);
//	printf("%s\n", p04);
//	printf("%s\n", p05);
//	printf("%s\n", p06);
//	printf("%s\n", p07);

	return(0);
}
*/

/*
int main (void)
{
	char *p08;
	char *p09;
	char *p10;
	char *p11;
	char *p12;
	char *p13;

	p08 = (char *)malloc(20);
	p09 = (char *)malloc(20);
	p10 = (char *)malloc(20);
	p11 = (char *)malloc(20);
	p12 = (char *)malloc(20);
	p13 = (char *)malloc(20);

	p08 = "###.\n#...\n....\n....\n";
	p09 = "#...\n##..\n.#..\n....\n";
	p10 = "#...\n###.\n....\n....\n";
	p11 = ".#..\n.#..\n##..\n....\n";
	p12 = ".#..\n##..\n.#..\n....\n";
	p13 = ".##.\n##..\n....\n....\n";

//	printf("%s\n", p08);
//	printf("%s\n", p09);
//	printf("%s\n", p10);
//	printf("%s\n", p11);
//	printf("%s\n", p12);
//	printf("%s\n", p13);

	return 0;
}
*/
/*
int main (void)
{
	char *p14;
	char *p15;
	char *p16;
	char *p17;
	char *p18;
	char *p19;

	p14 = (char *)malloc(20);
	p15 = (char *)malloc(20);
	p16 = (char *)malloc(20);
	p17 = (char *)malloc(20);
	p18 = (char *)malloc(20);
	p19 = (char *)malloc(20);

	p14 = ".#..\n###.\n....\n....\n";
	p15 = "##..\n.#..\n.#..\n....\n";
	p16 = "##..\n.##.\n....\n....\n";
	p17 = "..#.\n###.\n....\n....\n";
	p18 = "###.\n..#.\n....\n....\n";
	p19 = "####\n....\n....\n....\n";

	printf("%s\n\n", p14);
	printf("%s\n\n", p15);
	printf("%s\n\n", p16);
	printf("%s\n\n", p17);
	printf("%s\n\n", p18);
	printf("%s", p19);

	return(0);

}
*/
/*
int main (void)
{
	char p01[20];
	char p02[20];
	char p03[20];
	char p04[20];
	char p05[20];
	char p06[20];
	char p07[20];
	char p08[20];
	char p09[20];
	char p10[20];

	ft_strcpy(p01, "###.\n.#..\n....\n....\n");
	ft_strcpy(p02, "#...\n#...\n#...\n#...\n");
	ft_strcpy(p03, "##..\n#...\n#...\n....\n");
	ft_strcpy(p04, "#...\n##..\n#...\n....\n");
	ft_strcpy(p05, "#...\n#...\n##..\n....\n");
	ft_strcpy(p06, ".#..\n##..\n#...\n....\n");
	ft_strcpy(p07, "##..\n##..\n....\n....\n");
	ft_strcpy(p08, "###.\n#...\n....\n....\n");
	ft_strcpy(p09, "#...\n##..\n.#..\n....\n");
	ft_strcpy(p10, "#...\n###.\n....\n....\n");

	printf("%s\n\n", p01);
	printf("%s\n\n", p02);
	printf("%s\n\n", p03);
	printf("%s\n\n", p04);
	printf("%s\n\n", p05);
	printf("%s\n\n", p06);
	printf("%s\n\n", p07);
	printf("%s\n\n", p08);
	printf("%s\n\n", p09);
	printf("%s\n\n", p10);
	
	return(0);
}
*/

int main (void)
{
/*	
	char p11[20];
	char p12[20];
	char p13[20];
	char p14[20];
	char p15[20];
	char p16[20];
	char p17[20];
	char p18[20];
	char p19[20];	
	ft_strcpy(p11, ".#..\n.#..\n##..\n....\n");
	ft_strcpy(p12, ".#..\n##..\n.#..\n....\n");
	ft_strcpy(p13, ".##.\n##..\n....\n....\n");
	ft_strcpy(p14, ".#..\n###.\n....\n....\n");
	ft_strcpy(p15, "##..\n.#..\n.#..\n....\n");
	ft_strcpy(p16, "##..\n.##.\n....\n....\n");
	ft_strcpy(p17, "..#.\n###.\n....\n....\n");
	ft_strcpy(p18, "###.\n..#.\n....\n....\n");
	ft_strcpy(p19, "####\n....\n....\n....\n");
*/

// 19 valid pieces in a single array
/*
	printf("P01:\n%s\n\n", p01);
	printf("P02:\n%s\n\n", p02);
	printf("P03:\n%s\n\n", p03);
	printf("P04:\n%s\n\n", p04);
	printf("P05:\n%s\n\n", p05);
	printf("P06:\n%s\n\n", p06);
	printf("P07:\n%s\n\n", p07);
	printf("P08:\n%s\n\n", p08);
	printf("P09:\n%s\n\n", p09);
	printf("P10:\n%s\n\n", p10);
	printf("P11:\n%s\n\n", p11);
	printf("P12:\n%s\n\n", p12);
	printf("P13:\n%s\n\n", p13);
	printf("P14:\n%s\n\n", p14);
	printf("P15:\n%s\n\n", p15);
	printf("P16:\n%s\n\n", p16);
	printf("P17:\n%s\n\n", p17);
	printf("P18:\n%s\n\n", p18);
	printf("P19:\n%s\n", p19);
*/

	printf("p01:\n%d", p01[0]);


	return(0);
}

