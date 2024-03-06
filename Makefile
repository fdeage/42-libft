LIB_NAME = libft.a
SRC_DIR = ./src
INCLUDE_DIR = ./include
CC = gcc
FLAGS = -Wall -Wextra -Werror
EXTRAFLAGS = -Weverything -Wno-missing-prototypes --analyze -pedantic

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)
COL_B = \033[1;34m
COL_G = \033[1;32m
COL_RES = \033[0m

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $(LIB_NAME)
	@chmod +x $(LIB_NAME)
	@echo "$(COL_B)[BUILD:$(COL_G) DONE$(COL_B)]$(COL_RES)"

%.o: %.c
	$(CC) $(FLAGS) $(EXTRAFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	-@rm $(OBJ)

fclean : clean
	@rm $(LIB_NAME)

re: fclean $(LIB_NAME)

.PHONY: all clean fclean re
