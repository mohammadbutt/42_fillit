# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 15:25:32 by mbutt             #+#    #+#              #
#    Updated: 2019/05/19 16:15:30 by mbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -c
C_FILES = *.c
O_FILES = *.o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(C_FILES)	# Creates .o(object) files
	$(CC) -o $(NAME) $(O_FILES) # Takes .o files and creates fillit binary
#	ar rc $(NAME) $(O_FILES)	# Takes .o files and creates a static library
								# of NAME = fillit.a

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
