# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:52:41 by fhuang            #+#    #+#              #
#    Updated: 2017/11/02 19:54:33 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Editable =====
LIBDIR	:=	lib/
NAME	:=	$(addprefix $(LIBDIR), libft.a)
# ====================

# ===== Standard =====
CC		:=	clang -pipe
CFLAGS	:=	-Wall -Wextra -Werror -g3
SRCDIR	:=	src/
OBJDIR	:=	obj/
INCDIR	:=	include/
SRC		:=	$(shell basename $(shell find $(SRCDIR) -type f))
OBJ		:=	$(SRC:%.c=$(OBJDIR)%.o)
INC		:=	-I./$(INCDIR)
PRINTF	:= ./ft_printf
CACHEF	:=	.cache_exists
# ====================

# ====== Colors ======
CLEAR		= "\033[2K"
UP			= "\033[A"
EOC			= "\033[0;0m"
BLACK		= "\033[0;30m"
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
YELLOW		= "\033[0;33m"
BLUE		= "\033[0;34m"
PURPLE		= "\033[0;35m"
CYAN		= "\033[0;36m"
WHITE		= "\033[0;37m"
# ====================

EXEC			:= $(addprefix $(LIBDIR), $(NAME))
CACHEF			:=	.cache_exists

.PHONY: clean fclean re all
.SILENT:

all : $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32m" "-> Libft" "\033[0m"
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(CACHEF)
	$(CC) $(CFLAGS) -c  $< -o $@ $(INC)

$(CACHEF):
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(LIBDIR) || mkdir $(LIBDIR)
	test -d $(CACHEF) || touch $(CACHEF)

clean:
	rm -rf $(OBJDIR) $(CACHEF)

fclean: clean
	rm -f $(NAME)

re: fclean all
