# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:33:58 by otodd             #+#    #+#              #
#    Updated: 2023/12/04 16:57:17 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = ft_printf.c p_char.c p_str.c p_utils.c p_arth.c p_ptr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

clean:
	rm -r $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
