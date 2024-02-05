# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:33:58 by otodd             #+#    #+#              #
#    Updated: 2024/02/05 20:44:05 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS := ft_printf.c \
	ft_printf_arth_u.c \
	ft_printf_arth.c \
	ft_printf_char.c \
	ft_printf_ptr.c \
	ft_printf_str.c \
	ft_printf_utils.c \
	ft_printf_char_array.c \
	ft_printf_nbr_array.c

YELLOW := \033[1;33m
RED := \033[1;31m
GREEN := \033[1;32m
NC := \033[0m

OBJS := $(SRCS:%.c=obj/%.o)

all: dir $(OBJS)

dir:
	@if [ ! -d "obj" ]; then \
		echo "[$(GREEN)FTPRINTF$(NC)]  Creating obj directory..."; \
		mkdir -p obj; \
	fi

obj/%.o: src/%.c
	@echo "[$(GREEN)FTPRINTF$(NC)]  Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "[$(YELLOW)FTPRINTF$(NC)]  Cleaning object files..."
	@rm -rf $(OBJS)
	@rm -rf obj

re: clean all