# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalves-p <dalves-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 17:10:18 by dalves-p          #+#    #+#              #
#    Updated: 2021/09/17 18:55:37 by dalves-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_MLX = ./mlx/
# clang so_long.c -L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz

NAME		=	so_long
CC			=	clang
SRCS		=	so_long.c
CFLAGS		=	-Wall -Wextra -Werror
# MLXFLAGS	=	-L $(PATH_MLX) -lmlx -Ilmlx -lXext -lX11 (LINUX)
# MLXFLAGS	=	-L $(PATH_MLX) -lmlx -framework OpenGL -framework AppKit -lz (MACOS)
RM			=	rm -f
OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

# $(NAME):	$(OBJS)
# 			make -C libft/
# 			ar rcs $(NAME) $(OBJS) libft/*.o

.c.o:
			$(CC) $(CFLAGS) -c $<

clean:
			$(RM) $(OBJS)

# bonus:		all

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re
