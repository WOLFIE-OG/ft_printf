/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:06:27 by otodd             #+#    #+#             */
/*   Updated: 2023/12/04 16:15:47 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static size_t	parse_type(const char *in, va_list arg)
{
	if (*in == 'c')
		return (p_char(va_arg(arg, int)));
	else if (*in == 's')
		return (p_str(va_arg(arg, char *)));
	else if (*in == 'p')
		return (1);
	else if (*in == 'd' || *in == 'i')
		return (p_arth(va_arg(arg, int), 10));
	else if (*in == 'u')
		return (1);
	else if (*in == 'x')
		return (p_arth(va_arg(arg, int), 16));
	else if (*in == 'X')
		return (1);
	else if (*in == '%')
		return (p_char('%'));
	return (0);
}

int	ft_printf(const char *in, ...)
{
	va_list	args;
	size_t	i;

	i = 0;
	va_start(args, in);
	while (*in)
	{
		if (*in == '%')
		{
			in++;
			if (p_strchr("cspdiuxX%", *in))
				i += parse_type(in, args);
		}
		else
			i += p_char(*in);
		in++;
	}
	va_end(args);
	printf("\n%ld THIS IS THE REAL FUCKING RESULT\n", i - 1);
	return (i - 1);
}
