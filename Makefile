# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkergast <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:06:19 by rkergast          #+#    #+#              #
#    Updated: 2019/01/11 13:35:17 by rkergast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define SRC_NAME
afficher.c chainedlist.c createtab.c error.c ft_utils.c\
libft/get_next_line.c input.c move.c fulfilltab.c main.c\
libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memccpy.c libft/ft_memmove.c\
libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strlen.c libft/ft_strdup.c\
libft/ft_strcpy.c libft/ft_strncpy.c libft/ft_strcat.c libft/ft_strncat.c\
libft/ft_strlcat.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strstr.c\
libft/ft_strnstr.c libft/ft_strcmp.c libft/ft_strncmp.c libft/ft_atoi.c\
libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c\
libft/ft_isprint.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_memalloc.c\
libft/ft_memdel.c libft/ft_strnew.c libft/ft_strdel.c libft/ft_strclr.c\
libft/ft_striter.c libft/ft_striteri.c libft/ft_strmap.c libft/ft_strmapi.c\
libft/ft_strequ.c libft/ft_strnequ.c libft/ft_strsub.c libft/ft_strjoin.c\
libft/ft_strtrim.c libft/ft_strsplit.c libft/ft_itoa.c libft/ft_putchar.c\
libft/ft_putstr.c libft/ft_putendl.c libft/ft_putnbr.c libft/ft_putchar_fd.c\
libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c\
libft/ft_lstnew.c libft/ft_lstdelone.c libft/ft_lstdel.c libft/ft_lstadd.c\
libft/ft_lstiter.c libft/ft_lstmap.c
endef

CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC:.c=.o)
SRC = $(SRC_NAME)
OBJ = $(OBJ_NAME)
NAME = fillit
LIB = fillit.a
.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all
