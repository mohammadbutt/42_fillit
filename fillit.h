/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:31:22 by mbutt             #+#    #+#             */
/*   Updated: 2019/04/27 14:48:38 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <limits.h>
# include "./libft/libft.h"

// Put protptypes here if any

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

char	**ft_grid(int);

#endif
