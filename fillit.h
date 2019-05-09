/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:31:22 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/08 16:11:24 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <limits.h>
# include "./libft/libft.h"

// Put protptypes here if any


// -- 19 valid pieces in a single array
/*
# define p01 "###.\n.#..\n....\n....\n" 0+1+2+6   = 9
# define p02 "#...\n#...\n#...\n#...\n" 0+5+10+15 = 30
# define p03 "##..\n#...\n#...\n....\n" 0+1+5+10  = 16
# define p04 "#...\n##..\n#...\n....\n" 0+5+6+10  = 21
# define p05 "#...\n#...\n##..\n....\n" 0+5+10+11 = 26
# define p06 ".#..\n##..\n#...\n....\n" 1+5+6+10  = 21
# define p07 "##..\n##..\n....\n....\n" 0+1+5+6   = 12
# define p08 "###.\n#...\n....\n....\n" 0+1+2+5   = 8
# define p09 "#...\n##..\n.#..\n....\n" 0+5+6+11  = 22
# define p10 "#...\n###.\n....\n....\n" 0+5+6+7   = 18
# define p11 ".#..\n.#..\n##..\n....\n" 1+6+10+11 = 28
# define p12 ".#..\n##..\n.#..\n....\n" 1+5+6+11  = 23
# define p13 ".##.\n##..\n....\n....\n" 1+2+5+6   = 14 
# define p14 ".#..\n###.\n....\n....\n" 1+5+6+7   = 19
# define p15 "##..\n.#..\n.#..\n....\n" 0+1+6+11  = 18
# define p16 "##..\n.##.\n....\n....\n" 0+1+6+7   = 14
# define p17 "..#.\n###.\n....\n....\n" 2+5+6+7   = 20
# define p18 "###.\n..#.\n....\n....\n" 0+1+2+7   = 10
# define p19 "####\n....\n....\n....\n" 0+1+2+3   = 6
*/
/*
# define p01 (int[8]) {0,0, 	1,0, 	2,0, 	1,1}
# define p02 (int[8]) {0,0, 	0,1, 	0,2, 	0,3}
# define p03 (int[8]) {0,0, 	1,0,	0,1,	0,2}
# define p04 (int[8]) {0,0,		0,1,	1,1,	0,2}
# define p05 (int[8]) {0,0,		0,1,	0,2,	1,2}
# define p06 (int[8]) {1,0,		0,1,	1,1,	0,2}
# define p07 (int[8]) {0,0,		1,0,	0,1,	1,1}
# define p08 (int[8]) {0,0,		1,0,	2,0,	0,1}
# define p09 (int[8]) {0,0,		0,1,	1,1,	1,2}
# define p10 (int[8]) {0,0,		0,1,	1,1,	2,1}
# define p11 (int[8]) {1,0,		1,1,	0,2,	1,2}
# define p12 (int[8]) {1,0,		0,1,	1,1,	1,2}
# define p13 (int[8]) {1,0,		2,0,	0,1,	1,1}
# define p14 (int[8]) {1,0,		0,1,	1,1,	2,1}
# define p15 (int[8]) {0,0,		1,0,	1,1,	1,2}
# define p16 (int[8]) {0,0,		1,0,	1,1,	2,1}
# define p17 (int[8]) {2,0,		0,1,	1,1,	2,1}
# define p18 (int[8]) {0,0,		1,0,	2,0,	2,1}
# define p19 (int[8]) {0,0,		1,0,	2,0,	3,0}
*/
typedef struct s_tetro
{
	char *characters;
	char c; // carry alphabets
	struct s_tetro *next;
}		t_tetro;

t_tetro **ft_new(char **characters);

char	**ft_grid(int);

#endif
