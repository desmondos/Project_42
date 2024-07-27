NAME = pipex

SRCS_DIR = sources

SRCS = $(SRCS_DIR)/pipex.c $(SRCS_DIR)/pipex_utils_1.c \
	   $(SRCS_DIR)/pipex_utils_2.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_DIR = Libft

LIBFT = $(LIBFT_DIR)/libft.a

INCS = -I$(LIBFT_DIR)/includes

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} $(INCS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean

re: fclean all

.PHONY: all fclean clean re

