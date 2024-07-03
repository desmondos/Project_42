NAME = fdf

SRCS = fdf.c display.c draw.c draw_utils.c map_info.c \
	   ft_atoibase.c rotate.c seg_algo.c utils.c utils_x2.c \
	   utils_x3.c utils_x4.c win_set.c get_next_line.c \
	   get_next_line_utils.c utils_x5.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_DIR =  ../minilibx-linux

MLX_LIB = -L${MLX_DIR} -lmlx -lXext -lX11

MLX_INC = -I${MLX_DIR}

RM = rm -f

LIBFT_DIR = ../Libft

LIBFT = ${LIBFT_DIR}/libft.a

LIBFT_INC = -I${LIBFT_DIR}/includes

INCS = ${LIBFT_INC} ${MLX_INC}

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MLX_LIB} -lm -o ${NAME}

.c.o:
	@${CC} ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o}

${LIBFT}:
	@make -C ${LIBFT_DIR}

fclean: clean
	@${RM} ${NAME}
	@make -C ${LIBFT_DIR} fclean

clean:
	@${RM} ${OBJS}
	@make -C ${LIBFT_DIR} clean

re: fclean all

.PHONY: all fclean clean re
