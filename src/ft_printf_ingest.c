/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ingest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:29:06 by otodd             #+#    #+#             */
/*   Updated: 2024/03/28 12:46:58 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_printf_parse_type(const char *in, va_list arg, int fd)
{
	if (*in == 'c')
		return (ft_printf_char(va_arg(arg, int), fd));
	else if (*in == 's')
		return (ft_printf_str(va_arg(arg, char *), fd));
	else if (*in == 'a')
		return (ft_printf_str_array(va_arg(arg, char **), fd));
	else if (*in == 'n')
		return (ft_printf_nbr_array(va_arg(arg, int *), (char *)in, fd));
	else if (*in == 'l' || *in == 'L')
		return (ft_printf_linked_list(va_arg(arg, t_list *), (char *)in, fd));
	else if (*in == 'p')
		return (ft_printf_ptr(va_arg(arg, uintptr_t), fd));
	else if (*in == 'd' || *in == 'i')
		return (ft_printf_arth(va_arg(arg, int), 10, 0, fd));
	else if (*in == 'u')
		return (ft_printf_arth_u(va_arg(arg, unsigned int), fd));
	else if (*in == 'x')
		return (ft_printf_arth(va_arg(arg, unsigned int), 16, 0, fd));
	else if (*in == 'X')
		return (ft_printf_arth(va_arg(arg, unsigned int), 16, 1, fd));
	else if (*in == '%')
		return (ft_printf_char('%', fd));
	else
		return (0);
}

size_t	ft_printf_parse_type_extra(const char *in, va_list arg, int fd)
{
	if (*in == 'q')
		return (ft_printf_arth_l(va_arg(arg, long), 10, 0, fd));
	else
		return (0);
}

void	ft_printf_extra_flags(const char **in)
{
	if (ft_printf_strchr("Lln", **in))
		if (ft_printf_strchr("xXbo", *(*in + 1)))
			(*in)++;
}

void	ft_printf_process(const char **in, va_list args, size_t *count, int fd)
{
	if (ft_printf_strchr("csanqlLpdiuxX%", **in))
	{
		*count += ft_printf_parse_type(*in, args, fd);
		*count += ft_printf_parse_type_extra(*in, args, fd);
	}
	else
	{
		*count += ft_printf_char('%', fd);
		*count += ft_printf_char(**in, fd);
	}
}
