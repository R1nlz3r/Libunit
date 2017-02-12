# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 19:59:01 by vcombey           #+#    #+#              #
#    Updated: 2017/02/12 17:12:01 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		unittest

#			Compilation

CC = 		clang
CFLAGS = 	-Wall -Wextra -Werror

#			Sources

REAL-TESTS =	real-tests/main.c							\
				real-tests/strlen/00_launcher.c				\
				real-tests/strlen/01_basic_test.c			\
				real-tests/strlen/02_medium_test.c			\
				real-tests/strlen/03_hard_test.c			\
				real-tests/atoi/00_launcher.c				\
				real-tests/atoi/01_void_test.c				\
				real-tests/atoi/02_basic_test_1.c			\
				real-tests/atoi/03_basic_test_2.c			\
				real-tests/atoi/04_basic_test_3.c			\
				real-tests/atoi/05_basic_test_4.c			\
				real-tests/atoi/06_space_test_1.c			\
				real-tests/atoi/07_space_test_2.c			\
				real-tests/atoi/08_error_test_1.c			\
				real-tests/atoi/09_error_test_2.c			\
				real-tests/atoi/10_tab_test.c				\
				real-tests/atoi/11_intmin_test.c			\
				real-tests/atoi/12_intmax_test.c			\

OBJ-RT =		$(REAL-TESTS:.c=.o)

TESTS =			tests/main.c								\
				tests/00_launcher.c							\
				tests/01_ok_test.c							\
				tests/02_ko_test.c							\
				tests/03_segfault_test.c					\
				tests/04_bus_error_test.c					\
				tests/05_abort_test.c						\
				tests/06_floating_point_exception_test.c	\

OBJ-T =			$(TESTS:.c=.o)


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
	@make affcompil-rt
	$(CC) $(CFLAGS) $(OBJ-RT) $(LIBPATH) $(FRAMEWORKPATH) -o $(NAME)
	@./$(NAME)

all: $(NAME)

test: fclean
	@cd framework; $(MAKE) -f Makefile
	@make affcompil-t
	$(CC) $(CFLAGS) $(OBJ-T) $(LIBPATH) $(FRAMEWORKPATH) -o $(NAME)
	@./$(NAME)

re: fclean all

glu: fclean all clean

#			Compilation Rules

affcompil-rt:
	@echo "$(BLU)--::Unittest Compilation::--$(DEF)"
	@make $(OBJ-RT)

affcompil-t:
	@echo "$(BLU)--::Unittest-tests Compilation::--$(DEF)"
	@make $(OBJ-T)


%.o: %$(REAL-TESTS).c
	$(CC) $(CFLAGS) -c -o $@ $^

%.o: %$(TESTS).c
	$(CC) $(CFLAGS) -c -o $@ $^

#			Clean Rules

clean:
	@cd framework; $(MAKE) -f Makefile clean
	@echo "$(PUR)--::Unittest Binary Delection::--$(DEF)"
	@rm -rf $(OBJ-RT) $(OBJ-T)

fclean: clean
	@echo "$(RED)--::Libft.a Delection::--$(DEF)"
	@echo "$(RED)--::Libunit.a Delection::--$(DEF)"
	@echo "$(RED)--::Unittest Delection::--$(DEF)"
	@rm -rf $(NAME) $(FRAMEWORKPATH) $(LIBPATH)
