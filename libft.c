/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 16:39:06 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/21 13:20:26 by mbutt            ###   ########.fr       */
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
** memdel frees memory and then sets the pointer to null, because values can
** still be accessed if freed with free(3).
*/

void ft_memdel(void **address)
{
	if(address)
	{
		free(*address);
		*address = NULL;
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

/*
** Copies string from source to destination and null terminates the destination
** string.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/*
** Writes n number of 0 bytes to a string. Useful when the same variable is used
** to store different values. For example, if a variable called placeholder was
** used to temporarily store some value, which is then stored to a different
** variable, then once placeholder is done storing the values onto the new
** variable, values for placeholder will be set to 0, so characters from previous
** value will be completely removed.
*/

void ft_bzero(char *string)
{
	int i;

	i = 0;
	while(string[i]!= '\0')
	{
		string[i] = 0;
		i++;
	}
}
