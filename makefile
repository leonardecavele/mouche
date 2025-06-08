# Nom de l'exécutable
NAME = mouche

# Compilateur
CC = gcc

# Dossiers
SRC_DIR = src
INC_DIR = include

# Tous les .c dans src/ et sous-dossiers
SRCS = $(shell find $(SRC_DIR) -name "*.c")

# Objets
OBJS = $(SRCS:.c=.o)

# Flags
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

# Règle par défaut
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

# Pour nettoyer les fichiers objets
clean:
	rm -f $(OBJS)

# Pour nettoyer tout (exécutable + objets)
fclean: clean
	rm -f $(NAME)

# Pour recompiler proprement
re: fclean all

.PHONY: all clean fclean re
