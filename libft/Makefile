EXECUTABLE_NAME = libft.a

COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -g

OBJ_DIR = bin

SRCS = $(wildcard ft_*.c)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(EXECUTABLE_NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(EXECUTABLE_NAME): $(OBJS)
	ar rcs $(EXECUTABLE_NAME) $(OBJ_DIR)/*

norm:
	norminette ft_*.c libft.h

test:
	clear
	cc program.c libft.a ANSI-color-codes.h -lbsd -g
	mv a.out libft.bin
	./libft.bin

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -r $(EXECUTABLE_NAME)

re: fclean
	make

.PHONY: all clean fclean re