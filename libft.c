/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 16:39:06 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/19 17:37:39 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Below are some libft functions
*/

/*
** ft_strdel frees memory and then sets the pointer to null. ft_strdel is used
** instead of free because values can still be accessed sometimes if they are
** freed using free(3)
*/

void	ft_strdel(char **string)
{
	if (string)
	{
		free(*string);
		*string = NULL;
	}
}

/*
** ft_putstr prints a string
*/

void	ft_putstr(const char *string)
{
	int i;

	i = 0;
	if (string[i])
		while (string[i])
			write(1, &string[i++], 1);
}
