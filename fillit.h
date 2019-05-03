/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:31:22 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/03 13:00:04 by mbutt            ###   ########.fr       */
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
# define p01 "###.\n.#..\n....\n....\n"
# define p02 "#...\n#...\n#...\n#...\n"
# define p03 "##..\n#...\n#...\n....\n"
# define p04 "#...\n##..\n#...\n....\n"
# define p05 "#...\n#...\n##..\n....\n"
# define p06 ".#..\n##..\n#...\n....\n"
# define p07 "##..\n##..\n....\n....\n"
# define p08 "###.\n#...\n....\n....\n"
# define p09 "#...\n##..\n.#..\n....\n"
# define p10 "#...\n###.\n....\n....\n"
# define p11 ".#..\n.#..\n##..\n....\n"
# define p12 ".#..\n##..\n.#..\n....\n"
# define p13 ".##.\n##..\n....\n....\n"
# define p14 ".#..\n###.\n....\n....\n"
# define p15 "##..\n.#..\n.#..\n....\n"
# define p16 "##..\n.##.\n....\n....\n"
# define p17 "..#.\n###.\n....\n....\n"
# define p18 "###.\n..#.\n....\n....\n"
# define p19 "####\n....\n....\n....\n"
*/

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
/*
typedef struct s_tetris
{
	char characters[26][21];
}		t_tetris;
*/
char	**ft_grid(int);

#endif
