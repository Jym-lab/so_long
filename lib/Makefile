# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 19:31:51 by yjoo              #+#    #+#              #
#    Updated: 2022/06/27 18:55:00 by yjoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wall -Wextra
RM = rm -f
NAME = libyjoo.a
TRASH = __.SYMDEF\ SORTED

LIB_DIR = ./libft
GNL_DIR = ./get_next_line
GNL_SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(GNL_OBJS)
		make -C $(LIB_DIR)
		cp $(LIB_DIR)/libft.a .
		ar -x libft.a
		ar rcs $(NAME) *.o $(GNL_OBJS)
		rm *.o libft.a $(TRASH)

clean : 
		make -C $(LIB_DIR) clean
		$(RM) $(GNL_OBJS)

fclean: clean
		make -C $(LIB_DIR) fclean
		$(RM) $(NAME)

re : fclean all

.PHONY: all re clean fclean
