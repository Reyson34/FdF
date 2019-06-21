# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcottet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 16:03:46 by fcottet           #+#    #+#              #
#    Updated: 2018/11/04 14:50:33 by fcottet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a
LIB_PATH = libft
SRC = ./src/fdf.c \
	  ./src/check_map.c \
	  ./src/keyboard.c \
	  ./src/mouse.c \
	  ./src/draw.c
OBJ = fdf.o check_map.o keyboard.o mouse.o draw.o
INC = /usr/local/include/
MNL = /usr/local/lib/
FRAME = -framework OpenGL -framework AppKit

HEAD = ./includes/fdf.h
GCH = $(HEAD:.h=.h.gch)

all: $(NAME)

$(NAME): ./includes/fdf.h
	make -C $(LIB_PATH)
	$(CC) $(FLAGS) -I $(INC) $(SRC) -L $(MNL) $(LIB) -lmlx $(FRAME) -o fdf

clean:
	rm -f $(OBJ) $(GCH)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all

.PHONY : all, clean, fclean, re
