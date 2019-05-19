/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:24:18 by mbutt             #+#    #+#             */
/*   Updated: 2019/05/03 15:24:53 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char **ft_tetrominoes(int fd)
{
	int bytes_read;
	int temp_bytes_read;
	char **characters;
	int i;

	i = 0;
	characters = (char **)malloc(sizeof(char *) * (26));
	characters[i] = (char *)malloc(sizeof(char) * (21));
	while((bytes_read = read(fd, characters[i], 21)) >= 20)
	{
		if(characters[i][4] != '\n' || characters[i][9] != '\n')
			ft_exit();
		if(characters[i][14] != '\n' || characters[i][19] != '\n')
			ft_exit();
		else
		{
			temp_bytes_read = bytes_read;
			characters[i][20] = '\0';
			i++;
			characters[i] = (char *)malloc(sizeof(char) * 21);
		}
	}
	free(characters[i]); // This has to be freed
	if (temp_bytes_read == 21)
		ft_exit();
	return(characters);
}
