NAME = fdf

SRC_DIR = ./sources/

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/main_utils.c $(SRC_DIR)/main_utils_1.c \
	  $(SRC_DIR)/draw_utils.c $(SRC_DIR)/extras_utils.c $(SRC_DIR)/keys_tools.c \
	  $(SRC_DIR)/colors_utils.c $(SRC_DIR)/algo_fdf.c $(SRC_DIR)/clean_utils.c \
	  $(SRC_DIR)/display_set.c $(SRC_DIR)/mouse_utils.c $(SRC_DIR)/matrix_utils.c \
	  $(SRC_DIR)/drawing.c $(SRC_DIR)/colors_utils_1.c $(SRC_DIR)/disp_set_utils.c \
	  $(SRC_DIR)/map_info.c $(SRC_DIR)/transformation.c $(SRC_DIR)/keys_utils.c \
	  $(SRC_DIR)/../get_next_line/get_next_line.c \
	  $(SRC_DIR)/../get_next_line/get_next_line_utils.c\

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_DIR =  ./minilibx-linux

MLX_LIB = -L${MLX_DIR} -lmlx -lXext -lX11

MLX_INC = -I${MLX_DIR}

RM = rm -f

LIBFT_DIR = ./Libft

LIBFT = ${LIBFT_DIR}/libft.a

LIBFT_INC = -I${LIBFT_DIR}/includes

PRINTF_DIR = ./ft_printf

PRINTF = ${PRINTF_DIR}/libftprintf.a

PRINTF_INC = -I${PRINTF_DIR}/includes

INCS = ${LIBFT_INC} ${PRINTF_INC} ${MLX_INC}

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT} ${PRINTF}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${PRINTF} ${MLX_LIB} -lm -o ${NAME}

.c.o:
	@${CC} ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o}

${LIBFT}:
	@make -C ${LIBFT_DIR}

${PRINTF}:
	@make -C ${PRINTF_DIR}

fclean: clean
	@${RM} ${NAME}
	@make -C ${LIBFT_DIR} fclean
	@make -C ${PRINTF_DIR} fclean

clean:
	@${RM} ${OBJS}
	@make -C ${LIBFT_DIR} clean
	@make -C ${PRINTF_DIR} clean

re: fclean all

.PHONY: all fclean clean re
