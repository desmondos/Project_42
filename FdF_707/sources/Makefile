NAME = fdf

SRCS = fdf_ok.c display.c draw_utils2_ok.c draw_utils_ok.c map_utils_ok.c \
	   matrix_ok.c seg_algo_ok.c map_utils2_ok.c utils2_ok.c \
	   utils_x3.c utils_x4.c keys_utils_ok.c get_next_line.c \
	   get_next_line_utils.c geom_ok.c

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
