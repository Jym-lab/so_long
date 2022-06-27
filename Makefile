# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 14:06:34 by yjoo              #+#    #+#              #
#    Updated: 2022/06/13 14:06:34 by yjoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
FSANI = -g3 -fsanitize=address
RM = rm -f
NAME = so_long
LIB = ./lib/

OS = $(shell uname -s)

ifeq ($(OS), Darwin)
	MLX = ./mlx
	LINK = -L $(MLX) -lmlx -framework OpenGL -framework AppKit
else
	MLX = ./minilibx-linux
	LINK = -L $(MLX) -lmlx -lm -lXext -lX11
endif

INCLUDE = -I include
SRCS_DIR = ./srcs
FILES = main.c map.c map_check.c img.c key_event.c
SRCS = $(addprefix $(addsuffix /, $(SRCS_DIR)), $(FILES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
		make -C $(LIB)
		make -C $(MLX)
		$(CC) -o $(NAME) $(OBJS) -L $(LIB) -lyjoo $(INCLUDE) $(LINK)

re: fclean all

clean:
		make -C $(LIB) clean
		make -C $(MLX) clean
		$(RM) $(OBJS)

fclean: clean
		make -C $(LIB) fclean
		$(RM) $(NAME)

.PHONY: all re clean fclean
