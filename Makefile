# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/26 18:08:14 by ltimsit-          #+#    #+#              #
#    Updated: 2019/05/26 18:15:42 by ltimsit-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
FLAGS = -Wall -Werror -Wextra
INCLUDE = -I include
SRCS = get_info.c get_next_line.c check_commands.c do_command.c
LIBFT = libft/libft.a
OSRCS = $(SRC: .c=.o)

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) $(SRCS) $(LIBFT)
