# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/16 23:26:49 by fhuang            #+#    #+#              #
#    Updated: 2017/11/03 14:39:00 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Editable =====
NAME	:=	fract_ol
# ====================

# ===== Standard =====
CC		:=	clang -pipe
CFLAGS	:=	-Wall -Wextra -Werror -g3
MLXFLAGS :=	-lmlx -framework OpenGL -framework Appkit
MLXDIR	:=	minilibx_macos/
SRCDIR	:=	src/
OBJDIR	:=	obj/
BINDIR	:=	bin/
INCDIR	:=	include/
LIBFT	:=	libft/
LIBDIR	:=	lib/
SRC		:=	add_iteration.c					\
			draw_burning_ship.c				\
			draw_corresponding_fractal.c	\
			draw_julia.c					\
			draw_mandelbrot.c				\
			fract_ol_create_image.c			\
			fract_ol_key_hook.c				\
			fract_ol_motion_hook.c			\
			fract_ol_mouse_hook.c			\
			fract_ol_quit.c					\
			get_fractal_name.c				\
			get_fractal_type.c				\
			init.c							\
			init_fractal_parameters.c		\
			main.c							\
			put_pixel_in_fractal.c			\
			reset_parameters.c				\
			translate.c						\
			zoom.c
OBJ		:=	$(SRC:%.c=$(OBJDIR)%.o)
INC		:=	-I./$(INCDIR) -I./$(LIBFT)$(INCDIR)
LIBPATH	:=	-lpthread -L./$(LIBFT)$(LIBDIR) -lft
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

.PHONY: all libft norme clean fclean re
.SILENT:

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(MLXFLAGS) $(CFLAGS) $(OBJ) -o $@ $(LIBPATH) $(INC)
	printf $(BLUE)" $@ compiled!\n"$(EOC)

$(OBJDIR)%.o: $(SRCDIR)%.c $(CACHEF)
	$(CC) $(CFLAGS) -c  $< -o $@ $(INC)
	printf $(BLUE)"|"$(EOC)

$(CACHEF):
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(CACHEF) || touch $(CACHEF)

%.c:
	printf $(RED)"Missing file : $@\n"$(EOC)

libft:
	make -C $(LIBFT)

norme:
	norminette $(SRCDIR) $(INCDIR) | grep -v Norme -B1 || true
	norminette $(LIBFT)$(SRCDIR) $(LIBFT)$(INCDIR) | grep -v Norme -B1 || true

clean:
	make -C $(LIBFT) clean
	rm -rf $(OBJDIR) $(CACHEF)
	printf $(YELLOW)"All objects removed\n"$(EOC)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)
	printf $(RED)"$(NAME) removed\n"$(EOC)

re: fclean all
