# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::  #
#    Makefile                                           :+:      :+:    :+:  #
#                                                     +:+ +:+         +:+    #
#    By: mekaraca <reaphenn@gmail.com>               +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+          #
#    Created: 2026/02/24 20:00:00 by mekaraca            #+#    #+#            #
#    Updated: 2026/02/24 20:00:00 by mekaraca         ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I.
SRC_DIR = .
ALG_DIR = algorithm
OP_DIR = operations
SRCS = \
	$(SRC_DIR)/push_swap.c \
	$(SRC_DIR)/init_stack_a.c \
	$(SRC_DIR)/parse_utils.c \
	$(SRC_DIR)/split.c \
	$(SRC_DIR)/stack.c \
	$(SRC_DIR)/index.c \
	$(ALG_DIR)/turk_sort.c \
	$(ALG_DIR)/turk_utils.c \
	$(ALG_DIR)/turk_calc.c \
	$(ALG_DIR)/turk_exec.c \
	$(OP_DIR)/push.c \
	$(OP_DIR)/rotate.c \
	$(OP_DIR)/rev_rotate.c \
	$(OP_DIR)/swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
