/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:06:27 by otodd             #+#    #+#             */
/*   Updated: 2023/12/07 16:46:42 by otodd            ###   ########.fr       */
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
		return (p_ptr(va_arg(arg, uintptr_t)));
	else if (*in == 'd' || *in == 'i')
		return (p_arth(va_arg(arg, int), 10, 0));
	else if (*in == 'u')
		return (p_arth_u(va_arg(arg, unsigned int)));
	else if (*in == 'x')
		return (p_arth(va_arg(arg, unsigned int), 16, 0));
	else if (*in == 'X')
		return (p_arth(va_arg(arg, unsigned int), 16, 1));
	else if (*in == '%')
		return (p_char('%'));
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
			if (p_strchr("cspdiuxX%", *in))
				i += parse_type(in, args);
			else
			{
				i += p_char('%');
				i += p_char(*in);
			}
		}
		else
			i += p_char(*in);
		in++;
	}
	va_end(args);
	return (i);
}
