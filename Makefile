# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvedesti <mvedesti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 22:52:16 by mvedesti          #+#    #+#              #
#    Updated: 2021/12/13 09:19:49 by mvedesti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = *.c libft/*.c

OBJ = *.o
all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -g -c $(SRC)
bonus: $(NAME)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all, clean, fclean, re
