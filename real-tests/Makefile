# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcombey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 19:59:01 by vcombey           #+#    #+#              #
#    Updated: 2017/02/11 14:05:57 by vcombey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	unitest

SRC =	main.c					\
		strlen/00_launcher.c	\
		strlen/01_basic_test.c	\
		strlen/02_medium_test.c	\
		strlen/03_hard_test.c	\

INCLUDE = libft/

OBJS = $(addprefix objs/, $(SRC:.c=.o))

CFLAGS += -Wall -g -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	gcc -g $(OBJS) -L ../framework/ -lunit -L ../libft -lft -o $(NAME)

clean:
	/bin/rm -rf objs

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

objs/%.o : %.c
	@/bin/mkdir -p objs
	/bin/mkdir -p objs/strlen
	gcc -g $(CFLAGS) -I $(INCLUDE) -c -o $@ $<

.PHONY: all clean fclean re
