# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 17:10:18 by dalves-p          #+#    #+#              #
#    Updated: 2021/10/31 15:01:00 by dalves-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_MLX	=	./mlx/
# clang so_long.c -L ./mlx -lmlx -framework OpenGL -framework AppKit -lz

NAME		=	so_long
CC			=	clang
SRCS		=	srcs/so_long.c \
				srcs/key_manager.c \
				srcs/maps.c \
				srcs/validate_map.c \
				srcs/error.c \
				srcs/movements.c \
				srcs/game.c \
				srcs/free_map.c \

LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror
# SANIT		=	-g3 -fsanitize=address
MLXFLAGS	=	-L $(PATH_MLX) -lmlx -framework OpenGL -framework AppKit -lz
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)

ifeq ($(shell uname), Linux)
PATH_MLX	=	./mlx_linux/
MLXFLAGS	=	-L $(PATH_MLX) -lmlx -Ilmlx -lXext -lX11
endif


all:		$(NAME)

$(NAME):	$(OBJS)
#			make -C libft	
#			make clean -C libft
			$(CC) $(SRCS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)
# 			clang so_long.c -L ./mlx -lmlx -framework OpenGL -framework AppKit -lz -o so_long

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

run:		all
			./$(NAME) maps/map.ber

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
#			make fclean -C libft/

re:			fclean all

git:
	@git add .
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"
# Para chamar: make git m="meu commit"

.PHONY:		all clean fclean re