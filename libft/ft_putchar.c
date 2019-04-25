/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:22:52 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/21 16:02:46 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
/*
** int main (void)
** {
**	char a = 'a';
**	char b = 'b';;
**	ft_putchar(a);
**	ft_putchar('\n');
**	putchar(b);
**	return(0);
**}
*/
