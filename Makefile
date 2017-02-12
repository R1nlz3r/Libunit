# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 19:59:01 by vcombey           #+#    #+#              #
#    Updated: 2017/02/12 10:46:49 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		unittest

#			Compilation

CC = 		clang
CFLAGS = 	-Wall -Wextra -Werror

#			Sources

SRC =	real-tests/main.c					\
		real-tests/strlen/00_launcher.c		\
		real-tests/strlen/01_basic_test.c	\
		real-tests/strlen/02_medium_test.c	\
		real-tests/strlen/03_hard_test.c	\
		real-tests/atoi/00_launcher.c		\
		real-tests/atoi/01_void_test.c		\
		real-tests/atoi/02_basic_test_1.c	\
		real-tests/atoi/03_basic_test_2.c	\
		real-tests/atoi/04_basic_test_3.c	\
		real-tests/atoi/05_basic_test_4.c	\
		real-tests/atoi/06_space_test_1.c	\
		real-tests/atoi/07_space_test_2.c	\
		real-tests/atoi/08_error_test_1.c	\
		real-tests/atoi/09_error_test_2.c	\
		real-tests/atoi/10_tab_test.c		\
		real-tests/atoi/11_intmin_test.c	\
		real-tests/atoi/12_intmax_test.c	\

OBJ =		$(SRC:.c=.o)

#			Library Path

LIBPATH =	libft/libft.a
FRAMEWORKPATH = framework/libunit.a

#			Colors

DEF =		\033[0m
GRA =		\033[1m
SOU =		\033[4m
BLI =		\033[5m
BLA =		\033[30m
RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[35m
CYA =		\033[36m
WHI =		\033[37m

#			Main Rules

$(NAME):
	@cd framework; $(MAKE) -f Makefile
	@make affcompil
	$(CC) $(CFLAGS) $(OBJ) $(LIBPATH) $(FRAMEWORKPATH) -o $(NAME)
	@./$(NAME)


all: $(NAME)

re: fclean all

glu: fclean all clean

#			Compilation Rules

affcompil:
	@echo "$(BLU)--::Libunit Compilation::--$(DEF)"
	@make $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

#			Clean Rules

clean:
	@echo "$(PUR)--::Binary Delection::--$(DEF)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)--::Libunit Delection::--$(DEF)"
	@rm -rf $(NAME)
