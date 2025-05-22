# Nom de l'exécutable final
NAME = mouche

# Compilateur
CC = gcc

# Dossiers
SRC_DIR = src
CHAR_DIR = $(SRC_DIR)/character
INC_DIR = include

# Fichiers sources
SRCS = $(SRC_DIR)/main.c \
       $(CHAR_DIR)/character.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Flags de compilation
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

# Règle par défaut
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
