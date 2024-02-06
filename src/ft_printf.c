/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:06:27 by otodd             #+#    #+#             */
/*   Updated: 2024/02/06 17:23:15 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	parse_type(const char *in, va_list arg)
{
	if (*in == 'c')
		return (ft_printf_char(va_arg(arg, int)));
	else if (*in == 's')
		return (ft_printf_str(va_arg(arg, char *)));
	else if (*in == 'a')
		return (ft_printf_char_array(va_arg(arg, char **)));
	else if (*in == 'n')
		return (ft_printf_nbr_array(va_arg(arg, int *)));
	else if (*in == 'l' || *in == 'L')
		return (ft_printf_linked_list(va_arg(arg, t_list *), (char *)in));
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

static void	ft_printf_extra_flags(const char **in)
{
	if (ft_printf_strchr("Ll", **in))
		if (ft_printf_strchr("abA", *(*in + 1)))
			(*in)++;
}

static void	ft_printf_process(const char **in, va_list args, size_t *count)
{
	if (ft_printf_strchr("csanlLpdiuxX%", **in))
		*count += parse_type(*in, args);
	else
	{
		*count += ft_printf_char('%');
		*count += ft_printf_char(**in);
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
			i += ft_printf_char(*in);
		in++;
	}
	va_end(args);
	return (i);
}
