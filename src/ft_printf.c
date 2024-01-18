/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:06:27 by otodd             #+#    #+#             */
/*   Updated: 2024/01/18 16:50:16 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	parse_type(const char *in, va_list arg)
{
	if (*in == 'c')
		return (ft_printf_char(va_arg(arg, int)));
	else if (*in == 's')
		return (ft_printf_str(va_arg(arg, char *)));
	else if (*in == 'p')
		return (ft_printf_ptr(va_arg(arg, uintptr_t)));
	else if (*in == 'd' || *in == 'i')
		return (ft_printf_arth(va_arg(arg, int), 10, 0));
	else if (*in == 'u')
		return (ft_printf_arth_u(va_arg(arg, unsigned int)));
	else if (*in == 'x')
		return (ft_printf_arth(va_arg(arg, unsigned int), 16, 0));
	else if (*in == 'X')
		return (ft_printf_arth(va_arg(arg, unsigned int), 16, 1));
	else if (*in == '%')
		return (ft_printf_char('%'));
	else
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
			if (ft_printf_strchr("cspdiuxX%", *in))
				i += parse_type(in, args);
			else
			{
				i += ft_printf_char('%');
				i += ft_printf_char(*in);
			}
		}
		else
			i += ft_printf_char(*in);
		in++;
	}
	va_end(args);
	return (i);
}
