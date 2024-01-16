# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wolfie <wolfie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:33:58 by otodd             #+#    #+#              #
#    Updated: 2024/01/16 16:06:41 by wolfie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = ft_printf.c \
	p_arth_u.c \
	p_arth.c \
	p_char.c \
	p_ptr.c \
	p_str.c \
	p_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) a.out

fclean: clean
	rm -f $(NAME)

test: re
	$(CC) test.c -g $(NAME)
	./a.out

norm:
	norminette $(SRCS) ft_printf.h

re: fclean all
