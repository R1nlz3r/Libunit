# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/11 16:02:15 by mapandel          #+#    #+#              #
#    Updated: 2020/02/21 18:34:22 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libunit.a

#			Compilation

CC = 		clang
CFLAGS = 	#-Wall -Wextra -Werror -Weverything

#			Sources

SRC =		unit_test.c \

OBJ =		$(SRC:.c=.o)

#			Library Path

LIB =		../libft
LIBPATH =	$(LIB)/libft.a
LIBINC	=	$(LIB)/includes

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

.PHONY:		all indextion re glu

$(NAME):	$(LIBPATH) $(OBJ)
	@make indextion

all:		$(NAME)

indextion:
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GRE)--::Libunit Indexed::--$(DEF)"

re:			fclean all

glu:		fclean all clean

#			Compilation Rules

$(LIBPATH):
	@cd $(LIB); $(MAKE) -f Makefile

%.o:		%.c
	$(CC) $(CFLAGS) -I $(LIBINC) -c -o $@ $^

#			Clean Rules

.PHONY:		fclean lfclean clean fclean

lclean:
	@cd $(LIB); $(MAKE) -f Makefile clean

lfclean:
	@cd $(LIB); $(MAKE) -f Makefile fclean

clean:		lclean
	@make clean_message
	@rm -rf $(OBJ)

fclean:		clean
	@make fclean_message
	@rm -rf $(NAME) $(LIBPATH)

#			Display

.PHONY:		clean_message fclean_message

clean_message:
	@echo "$(PUR)--::Unittest Framework Binary Delection::--$(DEF)"

fclean_message:
	@echo "$(RED)--::Executable and Library Delection::--$(DEF)"
