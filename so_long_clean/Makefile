# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 17:10:18 by dalves-p          #+#    #+#              #
#    Updated: 2021/11/12 18:47:40 by dalves-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

SRCS_BONUS	=	bonus/so_long_bonus.c \
				bonus/key_manager_bonus.c \
				bonus/maps_bonus.c \
				bonus/validate_map_bonus.c \
				bonus/error_bonus.c \
				bonus/movements_bonus.c \
				bonus/game_bonus.c \
				bonus/free_map_bonus.c \
				bonus/animation_bonus.c \
				bonus/enemy_bonus.c \
				bonus/enemy_move_bonus.c \

LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)


ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
endif


all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft	
			$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

bonus: 		$(OBJS_BONUS)
			make -C libft	
			$(CC) $(OBJS_BONUS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C libft/

re:			fclean all

git:
	@git add .
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"
# Para chamar: make git m="meu commit"

.PHONY:		all clean fclean re