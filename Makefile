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
#CFLAGS = -Wall -Wextra -Werror
FSANI = -g3 -fsanitize=address
RM = rm -f
NAME = so_long

OS = $(shell uname -s)

ifeq ($(OS), Darwin)
	MLX = ./mlx
	LINK = -L $(MLX) -lmlx -framework OpenGL -framework AppKit
else
	MLX = ./minilibx-linux
	LINK = -L $(MLX) -lmlx -lm -lXext -lX11
endif

INCLUDE = -I./include
SRCS_PATH = ./srcs
FILES = test.c
SRCS = $(addprefix $(addsuffix /, $(SRCS_PATH)), $(FILES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(OBJS) $(LINK) $(INCLUDE) -o $@

re: fclean all

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

.PHONY: all re clean fclean
