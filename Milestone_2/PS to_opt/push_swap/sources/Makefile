NAME = push_swap

SRCS = main.c ft_fill_stack.c ft_manage_error.c \
	   ft_push.c ft_push_swap.c ft_reverse_rot.c \
	   ft_rotate.c ft_sort.c ft_sort_utils.c ft_split.c \
	   ft_swap.c ft_utils.c push_swap_utils.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCS = ../includes\includes/push_swap.h

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

fclean: clean
	@${RM} ${NAME}

clean:
	@${RM} ${OBJS}

re: fclean all

.PHONY: all fclean clean re
