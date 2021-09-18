CC		=	clang
SRCS	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memmove.c \
			ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strlen.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c ft_atoi.c ft_toupper.c \
			ft_tolower.c ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_substr.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_itoa.c ft_split.c \

BONUS_S	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
			ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libft.a
HEADER	=	libft.h
RM		=	rm -f
OBJS	=	$(SRCS:.c=.o)
BONUS_O =	$(BONUS_S:.c=.o)

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $<

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(BONUS_O)
			ar rcs $(NAME) $(BONUS_O)


clean:
			$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
