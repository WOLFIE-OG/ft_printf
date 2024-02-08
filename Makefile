# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:33:58 by otodd             #+#    #+#              #
#    Updated: 2024/02/07 19:54:33 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
NAME := libftprintf.a
CFLAGS := -Wall -Wextra -Werror
SRCS := ft_printf.c \
	ft_printf_arth_u.c \
	ft_printf_arth.c \
	ft_printf_char.c \
	ft_printf_ptr.c \
	ft_printf_str.c \
	ft_printf_utils.c \
	ft_printf_char_array.c \
	ft_printf_nbr_array.c \
	ft_printf_linked_list.c

YELLOW := \033[1;33m
RED := \033[1;31m
GREEN := \033[1;32m
NC := \033[0m
OBJS := $(SRCS:%.c=obj/%.o)
BUILD_DIR = build

module: dir $(OBJS)

dir:
	@if [ ! -d "obj" ]; then \
		echo "[$(GREEN)FTPRINTF$(NC)]  Creating obj directory..."; \
		mkdir -p obj; \
	fi

obj/%.o: src/%.c include/*.h
	@echo "[$(GREEN)FTPRINTF$(NC)]  Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "[$(YELLOW)FTPRINTF$(NC)]  Cleaning object files..."
	@rm -rf $(OBJS)
	@rm -rf obj

fclean: clean
	@echo "[$(RED)FTPRINTF$(NC)]  Cleaning build files..."
	@rm -rf $(BUILD_DIR)/

all: dir $(OBJS)
	@if [ ! -d "$(BUILD_DIR)" ]; then \
		echo "[$(GREEN)FTGNL$(NC)]     Creating build directory..."; \
		mkdir -p $(BUILD_DIR); \
	fi
	@echo "[$(GREEN)FTGNL$(NC)]     Building standalone lib..."
	@ar -rcs $(NAME) $(OBJS)
	@mv $(NAME) $(BUILD_DIR)/

re: fclean all