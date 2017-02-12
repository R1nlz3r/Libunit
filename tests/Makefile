# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 19:59:01 by vcombey           #+#    #+#              #
#    Updated: 2017/02/12 19:46:55 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		unittest

#			Compilation

CC = 		clang
CFLAGS = 	-Wall -Wextra -Werror

#		``	Sources

TESTS =		main.c								\
			00_launcher.c						\
			01_ok_test.c						\
			02_ko_test.c						\
			03_segfault_test.c					\
			04_bus_error_test.c					\
			05_abort_test.c						\
			06_floating_point_exception_test.c	\
			07_timeout_test.c					\

OBJ-T =			$(TESTS:.c=.o)


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
	@make affcompil-t

all: $(NAME)

test: fclean $(NAME)
	$(CC) $(CFLAGS) $(OBJ-T) $(LIBPATH) $(FRAMEWORKPATH) -o $(NAME)
	@./$(NAME)

re: fclean all

glu: fclean all clean

#			Compilation Rules

affcompil-t:
	@echo "$(BLU)--::Unittest-tests Compilation::--$(DEF)"
	@make $(OBJ-T)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

#			Clean Rules

clean:
	@echo "$(PUR)--::Unittest Binary Delection::--$(DEF)"
	@rm -rf $(OBJ-T)

fclean: clean
	@echo "$(RED)--::Unittest Executable Delection::--$(DEF)"
	@rm -rf $(NAME)
