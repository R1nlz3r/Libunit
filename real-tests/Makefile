# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 19:59:01 by vcombey           #+#    #+#              #
#    Updated: 2017/02/12 17:59:56 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		unittest

#			Compilation

CC = 		clang
CFLAGS = 	-Wall -Wextra -Werror

#			Sources

REAL-TESTS =	main.c							\
				strlen/00_launcher.c			\
				strlen/01_basic_test.c			\
				strlen/02_medium_test.c			\
				strlen/03_hard_test.c			\
				atoi/00_launcher.c				\
				atoi/01_void_test.c				\
				atoi/02_basic_test_1.c			\
				atoi/03_basic_test_2.c			\
				atoi/04_basic_test_3.c			\
				atoi/05_basic_test_4.c			\
				atoi/06_space_test_1.c			\
				atoi/07_space_test_2.c			\
				atoi/08_error_test_1.c			\
				atoi/09_error_test_2.c			\
				atoi/10_tab_test.c				\
				atoi/11_intmin_test.c			\
				atoi/12_intmax_test.c			\

OBJ-RT =		$(REAL-TESTS:.c=.o)

#			Library Path

LIBPATH =	../libft/libft.a
FRAMEWORKPATH = ../framework/libunit.a

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
	@make affcompil-rt

all: $(NAME)

test: fclean $(NAME)
	$(CC) $(CFLAGS) $(OBJ-RT) $(LIBPATH) $(FRAMEWORKPATH) -o $(NAME)
	@./$(NAME)

re: fclean all

glu: fclean all clean

#			Compilation Rules

affcompil-rt:
	@echo "$(BLU)--::Unittest Compilation::--$(DEF)"
	@make $(OBJ-RT)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

#			Clean Rules

clean:
	@echo "$(PUR)--::Unittest Binary Delection::--$(DEF)"
	@rm -rf $(OBJ-RT)

fclean: clean
	@echo "$(RED)--::Unittest Executable Delection::--$(DEF)"
	@rm -rf $(NAME)
