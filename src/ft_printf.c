/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:06:27 by otodd             #+#    #+#             */
/*   Updated: 2024/03/13 15:55:00 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	parse_type(const char *in, va_list arg)
{
	if (*in == 'c')
		return (ft_printf_char(va_arg(arg, int), OUT));
	else if (*in == 's')
		return (ft_printf_str(va_arg(arg, char *), OUT));
	else if (*in == 'a')
		return (ft_printf_char_array(va_arg(arg, char **), OUT));
	else if (*in == 'n')
		return (ft_printf_nbr_array(va_arg(arg, int *), (char *)in, OUT));
	else if (*in == 'l' || *in == 'L')
		return (ft_printf_linked_list(va_arg(arg, t_list *), (char *)in, OUT));
	else if (*in == 'p')
		return (ft_printf_ptr(va_arg(arg, uintptr_t), OUT));
	else if (*in == 'd' || *in == 'i')
		return (ft_printf_arth(va_arg(arg, int), 10, 0, OUT));
	else if (*in == 'u')
		return (ft_printf_arth_u(va_arg(arg, unsigned int), OUT));
	else if (*in == 'x')
		return (ft_printf_arth(va_arg(arg, unsigned int), 16, 0, OUT));
	else if (*in == 'X')
		return (ft_printf_arth(va_arg(arg, unsigned int), 16, 1, OUT));
	else if (*in == '%')
		return (ft_printf_char('%', OUT));
	else
		return (0);
}

static size_t	parse_type_extra(const char *in, va_list arg)
{
	if (*in == 'q')
		return (ft_printf_arth_l(va_arg(arg, long), 10, 0, OUT));
	else if (*in == 'e')
		return (ft_printf_str(va_arg(arg, char *), ERR));
	else
		return (0);
}

static void	ft_printf_extra_flags(const char **in)
{
	if (ft_printf_strchr("Lln", **in))
		if (ft_printf_strchr("xXbo", *(*in + 1)))
			(*in)++;
}

static void	ft_printf_process(const char **in, va_list args, size_t *count)
{
	if (ft_printf_strchr("ecsanqlLpdiuxX%", **in))
	{
		*count += parse_type(*in, args);
		*count += parse_type_extra(*in, args);
	}
	else
	{
		*count += ft_printf_char('%', OUT);
		*count += ft_printf_char(**in, OUT);
	}
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
			ft_printf_process(&in, args, &i);
			ft_printf_extra_flags(&in);
		}
		else
			i += ft_printf_char(*in, OUT);
		in++;
	}
	va_end(args);
	return (i);
}
