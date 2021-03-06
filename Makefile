# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/26 18:08:14 by ltimsit-          #+#    #+#              #
#    Updated: 2019/06/04 14:34:31 by ltimsit-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
FLAGS = -Wall -Werror -Wextra
INCLUDE = -I include
SRCS = get_info.c get_next_line.c check_commands.c do_command.c mod_pile.c \
	   quick_sort.c
LIBFT = libft/libft.a
LIBFTPRINTF = libftprintf.a
OSRCS = $(SRC: .c=.o)

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) $(SRCS) $(LIBFT) $(LIBFTPRINTF)
