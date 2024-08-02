NAME = minishell

SRC_DIR = ./sources

SRCS = $(SRC_DIR)/main.c #$(SRC_DIR)/.c $(SRC_DIR)/.c \
	   $(SRC_DIR)/.c $(SRC_DIR)/.c $(SRC_DIR)/.c \
	   $(SRC_DIR)/.c $(SRC_DIR)/.c $(SRC_DIR)/.c \
	   $(SRC_DIR)/.c $(SRC_DIR)/.c $(SRC_DIR)/.c \
	   $(SRC_DIR)/.c \

OBJS = ${SRCS:.c=.o}

LIBFT_DIR = ./libft

LIBFT = ${LIBFT_DIR}/libft.a

LIBFT_INC = -I${LIBFT_DIR}/includes

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCS = ${LIBFT_INC}

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

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
