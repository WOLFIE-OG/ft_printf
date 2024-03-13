/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:33:53 by wolfie            #+#    #+#             */
/*   Updated: 2024/03/13 15:48:56 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_printf_placements(uintptr_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	ft_printf_convert_base(uintptr_t i)
{
	char	c;

	c = 'a';
	if (i < 10)
		return (i + '0');
	else
		return (i - 10 + c);
}

static int	ft_printf_out(char *string, int fd)
{
	size_t	i;

	i = 0;
	i += ft_printf_str("0x", fd);
	i += ft_printf_str(string, fd);
	free(string);
	return (i);
}

size_t	ft_printf_ptr(uintptr_t n, int fd)
{
	int			len;
	char		*string;

	if (!n)
		return (ft_printf_str("(nil)", fd));
	len = ft_printf_placements(n);
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len--] = '\0';
	while (len >= 0)
	{
		string[len--] = (ft_printf_convert_base(n % 16));
		n /= 16;
	}
	return (ft_printf_out(string, fd));
}
