# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 15:25:32 by mbutt             #+#    #+#              #
#    Updated: 2019/05/18 20:00:34 by mbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -c
C_FILES = ft_*.c
O_FILES = *.o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(C_FILES) #Creates .o file
	ar rc $(NAME) $(O_FILES) #takes each .o file and creates a static library libft.a \

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
