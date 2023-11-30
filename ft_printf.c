/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:06:27 by otodd             #+#    #+#             */
/*   Updated: 2023/11/30 17:56:58 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	parse_type(const char *in, void *args)
{
	size_t	i;

	(void)args;
	i = 0;
	if (*in == 'c')
		printf("Print a char");
	else if (*in == 's')
		printf("Print a string");
	else if (*in == 'p')
		printf("Print a pointer");
	else if (*in == 'd' || *in == 'i')
		printf("Print an int or digit");
	else if (*in == 'u')
		printf("Print an unsigned int");
	else if (*in == 'x')
		printf("Print a lowercase hex value");
	else if (*in == 'X')
		printf("Print a upper hex value");
	return (i);
}

int	ft_printf(const char *in, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, in);
	while (*in)
	{
		if (*in == '%')
		{
			in++;
			if (ft_strchr("cspdiuxX", *in))
				i += parse_type(in, va_arg(args, void *));
			else if (*in == '%')
				i += print_char('%');

		}
		in++;
	}
	va_end(args);
	return (i);
}
