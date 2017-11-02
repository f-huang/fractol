# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:52:41 by fhuang            #+#    #+#              #
#    Updated: 2017/11/02 14:37:25 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

CFLAGS = -c -g3 -Wall -Wextra -Werror

SRC_PATH = ./SRC/
SRC_NAME = $(shell ls SRC)
SRC = $(addprefix $(SRC_PATH), $(SCR_NAME))

OBJ_PATH = ./OBJ/
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

PRINTF_PATH = ./ft_printf
INCLUDE_PATH = -I ./include/
LIB_PATH = ./lib/

EXEC = $(addprefix $(LIB_PATH), $(NAME))

.PHONY: clean fclean re all

all : $(NAME)

$(NAME): $(OBJ) $(SRC)
	@echo "\033[32m" "-> Libft" "\033[0m"
	@mkdir -p $(LIB_PATH)
	@ar rc $(EXEC) $(OBJ)
	@ranlib $(EXEC)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(INCLUDE_PATH) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(EXEC)
	@rm -rf $(LIB_PATH)

re: fclean all
