# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkergast <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:06:19 by rkergast          #+#    #+#              #
#    Updated: 2018/12/19 15:33:57 by rkergast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define SRC_NAME
afficher.c chainedlist.c create_tab.c error.c ft_sqrt_up.c get_next_line.c\
input.c mainfillit.c move.c rmv_tab.c
endef

CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC:.c=.o)
SRC = $(SRC_NAME)
OBJ = $(OBJ_NAME)
NAME = fillit.out
.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -fv $(OBJ)

fclean: clean
	rm -fv $(NAME)

re: fclean all
