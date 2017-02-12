# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/11 16:02:15 by mapandel          #+#    #+#              #
#    Updated: 2017/02/12 15:25:45 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libunit.a

#			Compilation

CC = 		clang
CFLAGS = 	-Wall -Wextra -Werror

#			Sources

SRC =		unit_test.c \

OBJ =		$(SRC:.c=.o)

#			Library Path

LIBPATH =	../libft/libft.a

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
	@cd ../libft; $(MAKE) -f Makefile
	@make $(OBJ)
	@echo "$(GRE)--::Libunit.a Indextion::--$(DEF)"
	@ar rc $(NAME) $(OBJ) $(LIBPATH)
	@ranlib $(NAME)


all: $(NAME)

standard:
	@cd ../libft; $(MAKE) -f Makefile standard
	@norminette -R CheckForbiddenSourceHeader $(SRC)

re: fclean all

glu: fclean all clean

#			Compilation Rules

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

#			Clean Rules

clean:
	@cd ../libft; $(MAKE) -f Makefile clean
	@echo "$(PUR)--::Framework Binary Delection::--$(DEF)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)--::Libft.a Delection::--$(DEF)"
	@echo "$(RED)--::Libunit.a Delection::--$(DEF)"
	@rm -rf $(NAME) $(LIBPATH)
