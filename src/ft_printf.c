/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:06:27 by otodd             #+#    #+#             */
/*   Updated: 2024/03/22 19:34:50 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"


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
			ft_printf_process(&in, args, &i, OUT);
			ft_printf_extra_flags(&in);
		}
		else
			i += ft_printf_char(*in, OUT);
		in++;
	}
	va_end(args);
	return (i);
}

int	ft_printf_fd(int fd, const char *in, ...)
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
			ft_printf_process(&in, args, &i, fd);
			ft_printf_extra_flags(&in);
		}
		else
			i += ft_printf_char(*in, fd);
		in++;
	}
	va_end(args);
	return (i);
}