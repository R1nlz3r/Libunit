# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 03:03:10 by mapandel          #+#    #+#              #
#    Updated: 2017/02/11 14:01:07 by vcombey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libunit.a

#			Compilation

CC = 		clang
CFLAGS = 	-Wall -Wextra -Werror

#			Sources

SRC =		unit_test.c \

OBJ =		$(SRC:.c=.o)

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
	@make affcompil
	@echo "$(GRE)--::Library Indextion::--$(DEF)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

standard:
	@echo "$(YEL)--::Check Standard::--$(DEF)"
	@norminette -R CheckForbiddenSourceHeader $(SRC)

re: fclean all

glu: fclean all clean

#			Compilation Rules

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

affcompil:
	@echo "$(BLU)--::Library Compilation::--$(DEF)"
	@make $(OBJ)

#			Clean Rules

clean:
	@echo "$(PUR)--::Library Binary Delection::--$(DEF)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)--::Library Delection::--$(DEF)"
	@rm -rf $(NAME)
