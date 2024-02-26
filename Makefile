# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:33:58 by otodd             #+#    #+#              #
#    Updated: 2024/02/26 15:38:01 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW=\033[1;33m
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[0;34m
NC=\033[0m

CC 			= cc
NAME 		= libftprintf.a
CFLAGS 		= -Wall -Wextra -Werror

SRCS 		= 	ft_printf.c \
				ft_printf_arth_u.c \
				ft_printf_arth.c \
				ft_printf_char.c \
				ft_printf_ptr.c \
				ft_printf_str.c \
				ft_printf_utils.c \
				ft_printf_char_array.c \
				ft_printf_nbr_array.c \
				ft_printf_linked_list.c \
				ft_printf_arth_l.c

OBJS 		= $(SRCS:%.c=obj/%.o)
BUILD_DIR	= build

all: $(NAME)

$(NAME): $(OBJS) | $(BUILD_DIR)
	@echo "[$(GREEN)FTGNL$(NC)]     Building standalone lib..."
	@ar -rcs $(NAME) $(OBJS)
	@mv $(NAME) $(BUILD_DIR)/

$(BUILD_DIR):
	@if [ ! -d "$(BUILD_DIR)" ]; then \
		echo "[$(GREEN)FTGNL$(NC)]     Creating build directory..."; \
		mkdir -p $(BUILD_DIR); \
	fi

module: $(OBJS)

dir:
	@if [ ! -d "obj" ]; then \
		echo "[$(GREEN)FTPRINTF$(NC)]  Creating obj directory..."; \
		mkdir -p obj; \
	fi

obj/%.o: src/%.c include/*.h | dir
	@echo "[$(GREEN)FTPRINTF$(NC)]  Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "[$(YELLOW)FTPRINTF$(NC)]  Cleaning object files..."
	@rm -rf obj

fclean: clean
	@echo "[$(RED)FTPRINTF$(NC)]  Cleaning build files..."
	@rm -rf $(BUILD_DIR)/


re: fclean all

.PHONY: all clean fclean re