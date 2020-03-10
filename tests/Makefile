# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 19:59:01 by vcombey           #+#    #+#              #
#    Updated: 2020/02/11 16:37:53 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			unittest

#			Compilation

CC = 			clang
CFLAGS = 		-Wall -Wextra -Werror -Weverything

#			Sources

SRC =			main.c								\
				00_launcher.c						\
				01_ok_test.c						\
				02_ko_test.c						\
				03_segfault_test.c					\
				04_bus_error_test.c					\
				05_abort_test.c						\
				06_floating_point_exception_test.c	\
				07_timeout_test.c					\

OBJ =			$(SRC:.c=.o)

INC =			.

#			Library Path

LIB =			../libft
LIBPATH =		$(LIB)/libft.a
LIBINC	=		$(LIB)/includes

FRAMEWORK =		../framework
FRAMEWORKPATH =	$(FRAMEWORK)/libunit.a
FRAMEWORKINC =	$(FRAMEWORK)

#			Colors

DEF =			\033[0m
GRA =			\033[1m
SOU =			\033[4m
BLI =			\033[5m
BLA =			\033[30m
RED =			\033[31m
GRE =			\033[32m
YEL =			\033[33m
BLU =			\033[34m
PUR =			\033[35m
CYA =			\033[36m
WHI =			\033[37m

#			Main Rules

.PHONY:			all test re glu

$(NAME):		$(FRAMEWORKPATH) $(LIBPATH) $(OBJ)
	@make compile_message
	@make compile_executable

all:			$(NAME)

test:			$(NAME)
	@./$(NAME)

re:				fclean all

glu:			fclean all clean

#			Compilation Rules

$(FRAMEWORKPATH):
	@cd $(FRAMEWORK); $(MAKE) -f Makefile

$(LIBPATH):
	@cd $(LIB); $(MAKE) -f Makefile

%.o:			%.c
	$(CC) $(CFLAGS) -I $(INC) -I $(FRAMEWORKINC) -I $(LIBINC) -c -o $@ $^

compile_executable:
	@$(CC) $(CFLAGS) $(OBJ) $(LIBPATH) $(FRAMEWORKPATH) -o $(NAME)

#			Clean Rules

.PHONY:			fclean lfclean clean fclean

lclean:
	@cd $(FRAMEWORK); $(MAKE) -f Makefile clean

lfclean:
	@cd $(FRAMEWORK); $(MAKE) -f Makefile fclean

clean:			lclean
	@make clean_message
	@rm -rf $(OBJ)

fclean:			clean
	@make fclean_message
	@rm -rf $(NAME) $(FRAMEWORKPATH) $(LIBPATH)

#			Display

.PHONY:			compile_message clean_message fclean_message

compile_message:
	@echo "$(CYA)--::Compiled Unittest::--$(DEF)"

clean_message:
	@echo "$(PUR)--::Unittest Binary Delection::--$(DEF)"

fclean_message:
	@echo "$(RED)--::Unittest Executable Delection::--$(DEF)"
