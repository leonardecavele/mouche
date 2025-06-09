NAME = mouche
CC = gcc

SRC_DIR = src
INC_DIR = include

SRCS = $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
 