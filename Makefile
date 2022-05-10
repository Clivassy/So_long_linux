NAME = so_long

SRCS = ft_map_utils.c ft_create_map.c ft_moves.c ft_events.c main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/ft_utils_1.c libft/ft_itoa.c libft/ft_utils_2.c ft_draw_map.c ft_check_map.c ft_errors.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME} so_long.h
${NAME}: ${OBJS}
	make -C ./minilibx-linux
	mv ./minilibx-linux/libmlx.a ./libmlx.a
	@${CC} ${CFLAGS} ${OBJS} -I ./ -g -L ./ -lX11 -lmlx -lXext -o so_long

clean: 
	@${RM} ${OBJS}
	make -C ./minilibx-linux clean

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re