# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 19:59:01 by vcombey           #+#    #+#              #
#    Updated: 2017/02/12 07:48:43 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	unittest

SRC =	main.c					\
		strlen/00_launcher.c	\
		strlen/01_basic_test.c	\
		strlen/02_medium_test.c	\
		strlen/03_hard_test.c	\
		atoi/00_launcher.c		\
		atoi/01_void_test.c		\
		atoi/02_basic_test_1.c	\
		atoi/03_basic_test_2.c	\
		atoi/04_basic_test_3.c	\
		atoi/05_basic_test_4.c	\
		atoi/06_space_test_1.c	\
		atoi/07_space_test_2.c	\
		atoi/08_error_test_1.c	\
		atoi/09_error_test_2.c	\
		atoi/10_tab_test.c		\
		atoi/11_intmin_test.c	\
		atoi/12_intmax_test.c	\

INCLUDE = libft/

OBJS = $(addprefix objs/, $(SRC:.c=.o))

CFLAGS += -Wall -g -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@gcc -g $(OBJS) -L ../framework/ -lunit -L ../libft -lft -o $(NAME)
	@./unittest

clean:
	@/bin/rm -rf objs

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

objs/%.o : %.c
	@/bin/mkdir -p objs
	@/bin/mkdir -p objs/strlen
	@/bin/mkdir -p objs/atoi
	@gcc -g $(CFLAGS) -I $(INCLUDE) -c -o $@ $<

.PHONY: all clean fclean re
