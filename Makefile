# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 11:55:15 by jpelleti          #+#    #+#              #
#    Updated: 2019/05/07 11:00:31 by jpelleti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

HEADER = includes

SRC_DIR = srcs

SRC_FILES = ft_printf.c	\
			parser.c	\
			misc_ptf.c	\
			find_fct.c	\
			alph.c		\
			num1.c		\
			misc_num1.c	\
			num2.c		\
			misc_num2.c	\
			misc_calc.c	

LIBFT_DIR = libft

OBJS_DIR = objs
OBJS_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@echo "\n\033[0;33mCompiling libftprintf.a.. \033[0;32mSuccess!\033m\017"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[0;31m------------- [ \033[0;36mEVERYTHING IS OK \033[0;31m] -----------\033m\017\033[0m"

$(OBJS_DIR):
	@echo "\033[0;31m------ [ \033[0;35m$(NAME) by jpelleti && gjuste \033[0;31m] ------"
	@echo "\033[0;33mLinking Libft..\033[0m"
	@make -C $(LIBFT_DIR)
	@cp libft/libft.a ./$(NAME)
	@echo "\033[0;32mSuccess!\n\033[0m"
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER)
	@echo "\033[0;33mCompiling $<.. \033[0;32mSuccess!\033m\017\033[0m"

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
