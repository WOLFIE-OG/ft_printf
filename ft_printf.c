/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:06:27 by otodd             #+#    #+#             */
/*   Updated: 2023/12/01 17:06:21 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	parse_type(const char *in, va_list arg)
{
	size_t	i;

	i = 0;
	if (*in == 'c')
		i += p_char(va_arg(arg, int));
	else if (*in == 's')
		i += p_str(va_arg(arg, char *));
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
				i += parse_type(in, args);
			else if (*in == '%')
				i += p_char('%');

		}
		else
			i = i + p_char(*in);
		in++;
	}
	va_end(args);
	return (i);
}
