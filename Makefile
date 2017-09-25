# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/17 11:00:37 by ybitton           #+#    #+#              #
#    Updated: 2017/05/18 11:59:53 by ybitton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

LIB   = ./libft/libft.a

SRC =	./minishell.c \
		./minishell_cd_function.c \
		./minishell_env_function.c \
		./minishell_env_function1.c \
		./minishell_list_tools.c \
		./minishell_pars.c \
		./minishell_pars1.c \
		./minishell_tools.c \
		./minishell_tools1.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) :
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)
	@echo "\x1b[35m" [~Compilation done~] "\x1b[0m"

clean :
	@make -C ./libft clean
	@rm -f $(OBJ)
	@echo "\x1b[32m" [~Folders cleaned~] "\x1b[0m"

fclean : clean
	@rm -f $(NAME) $(LIB)

re : fclean all

.PHONY: all clean fclean re