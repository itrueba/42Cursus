
NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -fsanitize=address -g3
LMLX		= -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx
RM			= rm -rf
LIB			= Libft
MLX			= mlx

SRCS	=	main.c error.c open_file.c\
			src/main/check_name.c src/main/init_game.c src/main/map_tester.c src/main/star_game.c \
			src/map/check_wall.c src/map/create_maps.c src/map/finishable_map.c src/map/info_checker.c src/map/map_cheker.c \
			src/game/get_xpm.c src/game/move.c src/game/paint_map.c src/game/hook.c
			
OBJS	= 	$(SRCS:.c=.o)

all:		$(NAME)

%.o: %.c
		$(CC) $(CFLAGS)  -c $< -o $@

$(NAME):	$(OBJS) 
			make -C $(LIB)
			make  -C $(MLX)
			$(CC) $(CFLAGS) $(LMLX) $(MLX)/libmlx.a $(LIB)/libft.a -o $@ $^

clean:
			@make -C $(LIB) clean
			@make -C $(MLX) clean
			@$(RM) $(OBJS)

fclean:		clean
			@make -C $(LIB) fclean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

