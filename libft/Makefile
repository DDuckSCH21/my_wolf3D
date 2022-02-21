SRCS	=	ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlen.c		\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_isalpha.c	\
			ft_isdigit.c	\
			ft_strnstr.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_atoi.c		\
			ft_calloc.c		\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_putstrl.c	\
			ft_strdup.c		\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_substr.c		\
			ft_strjoin.c	\
			ft_split.c		\
			ft_strtrim.c	\
			ft_strmapi.c	\
			ft_itoa.c       \
			ft_putchar.c    \
			ft_isspace.c

OBJS	= $(SRCS:.c=.o)

NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

C 		= -c

O 		= -o

AR 		= -ar rsc

RM		= rm -f

.c.o:   =	${CC} ${CFLAGS} $(C) $< $(O) ${<:.c=.o}
# В Ubuntu - Error - Пустое имя переменной

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
