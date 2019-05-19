# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 15:25:32 by mbutt             #+#    #+#              #
#    Updated: 2019/05/18 21:08:46 by mbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a
CC = gcc
//CFLAGS = -Wall -Wextra -Werror -I. -c
//C_FILES = *.c
//O_FILES = *.o
C_FILES = valid.c coordinate.c maintain1.c maintain2.c linked_list.c backtracker.c main.c
O_FILES = valid.o coordinate.o maintain1.o maintain2.o linked_list.o backtracker.o main.o
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
