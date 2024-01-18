# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:33:58 by otodd             #+#    #+#              #
#    Updated: 2024/01/18 17:01:53 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
	ft_printf_arth_u.c \
	ft_printf_arth.c \
	ft_printf_char.c \
	ft_printf_ptr.c \
	ft_printf_str.c \
	ft_printf_utils.c

OBJS = $(SRCS:%.c=bin/%.o)

all: dir $(OBJS)

dir:
	@mkdir -p bin

bin/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS)
	rm -rf bin

re: fclean all
