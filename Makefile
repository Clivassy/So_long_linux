NAME = so_long

SRCS = ft_moves.c ft_events.c main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/ft_utils_1.c libft/ft_utils_2.c ft_draw_map.c ft_check_map.c ft_errors.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME} so_long.h
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -I ./ -g -L ./ -lX11 -lmlx -lXext -o so_long

clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re