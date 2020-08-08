# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 19:59:01 by vcombey           #+#    #+#              #
#    Updated: 2020/08/08 19:38:46 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			unittest

#			Compilation

CC = 			clang
CFLAGS = 		-Wall -Wextra -Werror -Weverything

#			Sources

SRC =			sources/main.c												\
				sources/general_tests/00_launcher.c							\
				sources/general_tests/01_no_argument.c						\
				sources/general_tests/02_invalid_command.c					\
				sources/general_tests/03_p_option_small_file.c				\
				sources/general_tests/04_p_option_medium_file.c				\
				sources/general_tests/05_p_option_large_file.c				\
				sources/general_tests/06_p_option_small_binary_file.c		\
				sources/general_tests/07_p_option_medium_binary_file.c		\
				sources/general_tests/08_p_option_large_binary_file.c		\
				sources/general_tests/09_p_option_dev_null.c				\
				sources/general_tests/10_p_option_empty_file.c				\
				sources/general_tests/11_q_option.c							\
				sources/general_tests/12_r_option.c							\
				sources/general_tests/13_s_option_small_string.c			\
				sources/general_tests/14_s_option_medium_string.c			\
				sources/general_tests/15_s_option_large_string.c			\
				sources/general_tests/16_s_option_small_binary_string.c		\
				sources/general_tests/17_s_option_medium_binary_string.c	\
				sources/general_tests/18_s_option_large_binary_string.c		\
				sources/general_tests/19_s_option_empty_string.c			\
				sources/general_tests/20_s_option_no_argument.c				\
				sources/general_tests/21_error_missing_file.c				\
				sources/general_tests/22_error_directory.c					\
				sources/general_tests/23_error_no_permission.c				\
				sources/general_tests/24_end_of_options.c					\
				sources/general_tests/25_options_multiple_p.c				\
				sources/general_tests/26_options_p_and_s.c					\
				sources/general_tests/27_options_q_and_r.c					\
				sources/general_tests/28_options_s_into_end_of_options.c	\
				sources/general_tests/29_options_mixup.c					\
				sources/md5/00_launcher.c									\
				sources/md5/01_small_file.c									\
				sources/md5/02_medium_file.c								\
				sources/md5/03_large_file.c									\
				sources/md5/04_small_binary_file.c							\
				sources/md5/05_medium_binary_file.c							\
				sources/md5/06_large_binary_file.c							\
				sources/md5/07_dev_null.c									\
				sources/md5/08_empty_file.c									\
				sources/md5/09_piped_small_file.c							\
				sources/md5/10_piped_medium_file.c							\
				sources/md5/11_piped_large_file.c							\
				sources/md5/12_piped_small_binary_file.c					\
				sources/md5/13_piped_medium_binary_file.c					\
				sources/md5/14_piped_large_binary_file.c					\
				sources/md5/15_piped_dev_null.c								\
				sources/md5/16_piped_empty_file.c							\
				sources/md5/17_no_argument_small_file.c						\
				sources/md5/18_no_argument_medium_file.c					\
				sources/md5/19_no_argument_large_file.c						\
				sources/md5/20_no_argument_small_binary_file.c				\
				sources/md5/21_no_argument_medium_binary_file.c				\
				sources/md5/22_no_argument_large_binary_file.c				\
				sources/md5/23_no_argument_dev_null.c						\
				sources/md5/24_no_argument_empty_file.c						\
				sources/md5/25_multiple_files.c								\
				sources/md5/26_multiple_files_with_errors.c					\
				sources/md5/27_multiple_binary_files.c						\
				sources/md5/28_multiple_binary_files_with_errors.c			\
				sources/md5/29_multiple_files_mixup.c						\
				sources/md5/30_multiple_files_mixup_with_errors.c			\
				sources/sha256/00_launcher.c								\
				sources/sha256/01_small_file.c								\
				sources/sha256/02_medium_file.c								\
				sources/sha256/03_large_file.c								\
				sources/sha256/04_small_binary_file.c						\
				sources/sha256/05_medium_binary_file.c						\
				sources/sha256/06_large_binary_file.c						\
				sources/sha256/07_dev_null.c								\
				sources/sha256/08_empty_file.c								\
				sources/sha256/09_piped_small_file.c						\
				sources/sha256/10_piped_medium_file.c						\
				sources/sha256/11_piped_large_file.c						\
				sources/sha256/12_piped_small_binary_file.c					\
				sources/sha256/13_piped_medium_binary_file.c				\
				sources/sha256/14_piped_large_binary_file.c					\
				sources/sha256/15_piped_dev_null.c							\
				sources/sha256/16_piped_empty_file.c						\
				sources/sha256/17_no_argument_small_file.c					\
				sources/sha256/18_no_argument_medium_file.c					\
				sources/sha256/19_no_argument_large_file.c					\
				sources/sha256/20_no_argument_small_binary_file.c			\
				sources/sha256/21_no_argument_medium_binary_file.c			\
				sources/sha256/22_no_argument_large_binary_file.c			\
				sources/sha256/23_no_argument_dev_null.c					\
				sources/sha256/24_no_argument_empty_file.c					\
				sources/sha256/25_multiple_files.c							\
				sources/sha256/26_multiple_binary_files.c					\
				sources/sha256/27_multiple_files_mixup.c					\
				sources/sha512/00_launcher.c								\
				sources/sha512/01_small_file.c								\
				sources/sha512/02_medium_file.c								\
				sources/sha512/03_large_file.c								\
				sources/sha512/04_small_binary_file.c						\
				sources/sha512/05_medium_binary_file.c						\
				sources/sha512/06_large_binary_file.c						\
				sources/sha512/07_dev_null.c								\
				sources/sha512/08_empty_file.c								\
				sources/sha512/09_piped_small_file.c						\
				sources/sha512/10_piped_medium_file.c						\
				sources/sha512/11_piped_large_file.c						\
				sources/sha512/12_piped_small_binary_file.c					\
				sources/sha512/13_piped_medium_binary_file.c				\
				sources/sha512/14_piped_large_binary_file.c					\
				sources/sha512/15_piped_dev_null.c							\
				sources/sha512/16_piped_empty_file.c						\
				sources/sha512/17_no_argument_small_file.c					\
				sources/sha512/18_no_argument_medium_file.c					\
				sources/sha512/19_no_argument_large_file.c					\
				sources/sha512/20_no_argument_small_binary_file.c			\
				sources/sha512/21_no_argument_medium_binary_file.c			\
				sources/sha512/22_no_argument_large_binary_file.c			\
				sources/sha512/23_no_argument_dev_null.c					\
				sources/sha512/24_no_argument_empty_file.c					\
				sources/sha512/25_multiple_files.c							\
				sources/sha512/26_multiple_binary_files.c					\
				sources/sha512/27_multiple_files_mixup.c					\

OBJ =			$(SRC:.c=.o)

INC =			includes

#			Project to test

FT_SSL =		Ft_ssl/
FT_SSL_EXE =	Ft_ssl/ft_ssl \
				Ft_ssl/ft_ssl_leak_report \

#			Junk Files

TMP =			trace/ \
				resources/perm

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

$(FT_SSL_EXE):
	@make -C $(FT_SSL)
	@make ft_ssl_leak_report -C $(FT_SSL)

all:			$(NAME)

test:			$(NAME) $(FT_SSL_EXE)
	@rm -rf $(TMP)
	@./$(NAME)
	@rm -rf $(FT_SSL_EXE)

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
	@rm -rf $(TMP) $(OBJ)

fclean:			clean
	@make fclean_message
	@rm -rf $(NAME) $(FRAMEWORKPATH) $(LIBPATH) $(FT_SSL_EXE)

#			Display

.PHONY:			compile_message clean_message fclean_message

compile_message:
	@echo "$(CYA)--::Compiled Unittest::--$(DEF)"

clean_message:
	@echo "$(PUR)--::Unittest Binary Delection::--$(DEF)"

fclean_message:
	@echo "$(RED)--::Unittest Executable Delection::--$(DEF)"
