# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:33:58 by otodd             #+#    #+#              #
#    Updated: 2023/12/08 18:10:24 by otodd            ###   ########.fr        #
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
	ar -r $(NAME) $(OBJS)

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
