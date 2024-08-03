NAME = minishell

SRC_DIR = ./source

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/main_utils.c $(SRC_DIR)/command.c \
	   $(SRC_DIR)/command_utils.c $(SRC_DIR)/in_out.c $(SRC_DIR)/in_out_utils.c \
	   $(SRC_DIR)/process.c $(SRC_DIR)/process_utils.c $(SRC_DIR)/shell.c \
	   $(SRC_DIR)/shell_utils.c $(SRC_DIR)/signal.c $(SRC_DIR)/signal_utils.c \
	   $(SRC_DIR)/utils.c \

OBJS = ${SRCS:.c=.o}

LIBFT_DIR = ./libft

LIBFT = ${LIBFT_DIR}/libft.a

LIBFT_INC = -I${LIBFT_DIR}/includes

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

LDFLAGS = -lreadline -lhistory

LIBDIR = ./readline/

INCS = ${LIBFT_INC}

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${LDFLAGS} -o ${NAME}

.c.o:
	@${CC} ${CFLAGS} -R${LIBDIR} -c $< -o ${<:.c=.o} -I${INCS}

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
