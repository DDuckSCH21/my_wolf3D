SRCS	=	ft_cub3d.c			\
			ft_parse_cub.c		\
			ft_parse_map.c		\
			ft_utils_cub3d.c	\
			ft_init_all.c		\
			ft_check_config.c	\
			ft_check_map.c		\
			ft_end.c			\
			ft_mlx.c			\
			ft_key_hook.c		\
			ft_raycasting.c		\
			ft_draw.c			\
			ft_rgb.c			\
			ft_sprite.c			\
			ft_sprite_draw.c	\
			ft_screen.c			\
			gnl/get_next_line.c	\
			gnl/get_next_line_utils.c

MLXDIR		=	minilibx

LIBFTDIR	=	libft

LMLX	=	-L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit

OBJS	=	$(SRCS:.c=.o)

HEAD	=	ft_cub3d.h $(MLXDIR)/mlx.h

NAME    =   cub3D

OBJS	=	$(SRCS:.c=.o)

RM		= 	rm -f

%.o:%.c
			gcc -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME):	$(OBJS) $(HEAD)
			make -C $(MLXDIR)
			make -C $(LIBFTDIR)
			$(CC) $(OBJS) $(LMLX) ./libft/libft.a -o $(NAME)

all:		$(NAME)

bonus:		clean $(NAME)


clean:
			$(RM) $(OBJS)
			make clean -C $(MLXDIR)
			make clean -C $(LIBFTDIR)

mlx:
			make -C $(MLXDIR)


fclean:		clean
			$(RM) $(NAME)
			make clean -C $(MLXDIR)
			make fclean -C $(LIBFTDIR)

re:			fclean all

.PHONY: 	all clean mlx fclean re

